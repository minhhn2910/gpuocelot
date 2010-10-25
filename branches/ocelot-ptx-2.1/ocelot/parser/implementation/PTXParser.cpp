/*! \file PTXParser.cpp
	\date Monday January 19, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the PTXParser class.
*/

#ifndef PTX_PARSER_CPP_INCLUDED
#define PTX_PARSER_CPP_INCLUDED

#include <ocelot/parser/interface/PTXParser.h>
#include <cassert>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/string.h>

#define throw_exception( messageData, type ) \
	{\
		std::stringstream error;\
		error << messageData;\
		parser::PTXParser::Exception exception;\
		exception.error = type;\
		exception.message = error.str();\
		throw exception;\
	}
	
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

/*! \brief A namespace for parsing PTX */
namespace ptx
{ 
	extern int yyparse( parser::PTXLexer&, parser::PTXParser::State& );
}

namespace parser
{
	PTXParser::State::OperandWrapper::OperandWrapper( const ir::PTXOperand& o, 
		ir::PTXInstruction::AddressSpace s ) : operand( o ), space( s )
	{
	
	}

	void PTXParser::State::FunctionPrototype::clear()
	{
		returnTypes.clear();
		argumentTypes.clear();
		name.clear();
	}

	bool PTXParser::State::FunctionPrototype::compare( 
		const FunctionPrototype& t )
	{
		return t.returnTypes == returnTypes 
			&& t.argumentTypes == argumentTypes;
	}
	
	std::string PTXParser::State::FunctionPrototype::toString() const
	{
		std::stringstream stream;
		
		stream << "(";
		for( TypeVector::const_iterator type = returnTypes.begin(); 
			type != returnTypes.end(); ++type )	
		{
			if( type != returnTypes.begin() )
			{
				stream << ", ";
			}
			stream << ir::PTXOperand::toString( *type );
		}

		stream << ") " << name << " (";

		for( TypeVector::const_iterator type = argumentTypes.begin(); 
			type != argumentTypes.end(); ++type )	
		{
			if( type != argumentTypes.begin() )
			{
				stream << ", ";
			}
			stream << ir::PTXOperand::toString( *type );
		}		
		stream << ")";
		
		return stream.str();
	}

	ir::PTXInstruction::AddressSpace PTXParser::State::_toAddressSpace( 
		ir::PTXStatement::Directive directive )
	{
		switch( directive )
		{
			case ir::PTXStatement::Shared : return ir::PTXInstruction::Shared;
			case ir::PTXStatement::Local : return ir::PTXInstruction::Local;
			case ir::PTXStatement::Param : return ir::PTXInstruction::Param;
			case ir::PTXStatement::Global : return ir::PTXInstruction::Global;
			case ir::PTXStatement::Const : return ir::PTXInstruction::Const;
			default: break;
		}
		return ir::PTXInstruction::AddressSpace_Invalid;
	}
	
	void PTXParser::State::_setImmediateTypes()
	{		
		ir::PTXOperand::DataType type = ir::PTXOperand::TypeSpecifier_invalid;
		for( OperandVector::iterator operand = operandVector.begin(); 
			operand != operandVector.end(); ++operand )
		{
			if( operand->addressMode != ir::PTXOperand::Immediate 
				&& operand->addressMode != ir::PTXOperand::Invalid
				&& operand->type != ir::PTXOperand::pred )
			{
				type = operand->type;
			}
		}
		
		if( type == ir::PTXOperand::TypeSpecifier_invalid ) return;
		
		for( OperandVector::iterator operand = operandVector.begin(); 
			operand != operandVector.end(); ++operand )
		{
			if( operand->addressMode == ir::PTXOperand::Immediate 
				&& ( ir::PTXOperand::isFloat( operand->type ) 
				== ir::PTXOperand::isFloat( type ) ) )
			{
				operand->type = type;
			}
		}
	}

	static ir::PTXOperand::SpecialRegister envReg( unsigned int i )
	{
		switch( i )
		{
			case 0: return ir::PTXOperand::envreg0;
			case 1: return ir::PTXOperand::envreg1;
			case 2: return ir::PTXOperand::envreg2;
			case 3: return ir::PTXOperand::envreg3;
			case 4: return ir::PTXOperand::envreg4;
			case 5: return ir::PTXOperand::envreg5;
			case 6: return ir::PTXOperand::envreg6;
			case 7: return ir::PTXOperand::envreg7;
			case 8: return ir::PTXOperand::envreg8;
			case 9: return ir::PTXOperand::envreg9;
			case 10: return ir::PTXOperand::envreg10;
			case 11: return ir::PTXOperand::envreg11;
			case 12: return ir::PTXOperand::envreg12;
			case 13: return ir::PTXOperand::envreg13;
			case 14: return ir::PTXOperand::envreg14;
			case 15: return ir::PTXOperand::envreg15;
			case 16: return ir::PTXOperand::envreg16;
			case 17: return ir::PTXOperand::envreg17;
			case 18: return ir::PTXOperand::envreg18;
			case 19: return ir::PTXOperand::envreg19;
			case 20: return ir::PTXOperand::envreg20;
			case 21: return ir::PTXOperand::envreg21;
			case 22: return ir::PTXOperand::envreg22;
			case 23: return ir::PTXOperand::envreg23;
			case 24: return ir::PTXOperand::envreg24;
			case 25: return ir::PTXOperand::envreg25;
			case 26: return ir::PTXOperand::envreg26;
			case 27: return ir::PTXOperand::envreg27;
			case 28: return ir::PTXOperand::envreg28;
			case 29: return ir::PTXOperand::envreg29;
			case 30: return ir::PTXOperand::envreg30;
			case 31: return ir::PTXOperand::envreg31;
			default: break;
		}
		return ir::PTXOperand::SpecialRegister_invalid;
	}

	void PTXParser::State::addSpecialRegisters()
	{
		operands.insert( std::make_pair( "%tid", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::tid, ir::PTXOperand::iAll ) ) ) );
		operands.insert( std::make_pair( "%ntid", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::ntid, ir::PTXOperand::iAll ) ) ) );
		operands.insert( std::make_pair( "%laneid", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::laneId, ir::PTXOperand::ix ) ) ) );
		operands.insert( std::make_pair( "%nwarpid", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::nwarpId, ir::PTXOperand::ix ) ) ) );
		operands.insert( std::make_pair( "%ctaid", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::ctaId, ir::PTXOperand::iAll ) ) ) );
		operands.insert( std::make_pair( "%nctaid", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::nctaId,
			ir::PTXOperand::iAll ) ) ) );
		operands.insert( std::make_pair( "%simd", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::smId, ir::PTXOperand::ix ) ) ) );
		operands.insert( std::make_pair( "%nsmid", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::nsmId, ir::PTXOperand::ix ) ) ) );
		operands.insert( std::make_pair( "%gridId", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::gridId, ir::PTXOperand::ix ) ) ) );

		operands.insert( std::make_pair( "%lanemask_eq", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::lanemask_eq,
			ir::PTXOperand::ix ) ) ) );
		operands.insert( std::make_pair( "%lanemask_le", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::lanemask_le,
			ir::PTXOperand::ix ) ) ) );
		operands.insert( std::make_pair( "%lanemask_lt", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::lanemask_lt,
			ir::PTXOperand::ix ) ) ) );
		operands.insert( std::make_pair( "%lanemask_ge", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::lanemask_ge,
			ir::PTXOperand::ix ) ) ) );
		operands.insert( std::make_pair( "%lanemask_gt", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::lanemask_gt,
			ir::PTXOperand::ix ) ) ) );

		operands.insert( std::make_pair( "%clock", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::clock, ir::PTXOperand::ix ) ) ) );
		operands.insert( std::make_pair( "%clock64", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::clock64, ir::PTXOperand::ix, 
			ir::PTXOperand::u64 ) ) ) );

		operands.insert( std::make_pair( "%pm0", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::pm0, ir::PTXOperand::ix ) ) ) );
		operands.insert( std::make_pair( "%pm1", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::pm1, ir::PTXOperand::ix ) ) ) );
		operands.insert( std::make_pair( "%pm2", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::pm2, ir::PTXOperand::ix ) ) ) );
		operands.insert( std::make_pair( "%pm3", OperandWrapper( 
			ir::PTXOperand( ir::PTXOperand::pm3, ir::PTXOperand::ix ) ) ) );

		for( unsigned int i = 0; i < 32; ++i )
		{
			std::stringstream stream;
			stream << "%envreg" << i;
			
			operands.insert( std::make_pair( stream.str(), OperandWrapper( 
				ir::PTXOperand( envReg( i ), ir::PTXOperand::ix, 
				ir::PTXOperand::b32 ) ) ) );			
		}
	}

	void PTXParser::State::maxnreg( unsigned int regs )
	{
		report( "  Rule: TOKEN_MAXNREG TOKEN_DECIMAL_CONSTANT" );
	}
	
	void PTXParser::State::maxntid( unsigned int tidx, unsigned int tidy, 
		unsigned int tidz )
	{
		report( "  Rule: TOKEN_MAXNTID TOKEN_DECIMAL_CONSTANT" );
	}
	
	void PTXParser::State::ctapersm( int target, unsigned int ctas )
	{
		report( "  Rule: shareModel ':' TOKEN_DECIMAL_CONSTANT" );
	}
	
	void PTXParser::State::maxnctapersm( unsigned int ctas )
	{
		report( "  Rule: TOKEN_MAXNCTAPERSM TOKEN_DECIMAL_CONSTANT" );
	}
	
	void PTXParser::State::maxnctapersm()
	{
		report( "  Rule: TOKEN_MAXNCTAPERSM ctapersmList" );
	}

	void PTXParser::State::preprocessor( int token )
	{
		throw_exception( "PTX preprocessor commands not supported in Ocelot.", 
			NotSupported );
	}

	void PTXParser::State::version( double version, YYLTYPE& location )
	{
		report( "  Rule: VERSION DOUBLE_CONSTANT" );

		std::stringstream stream1;
		stream1.setf( std::ios::fixed, std::ios::floatfield );
		stream1.precision( 1 );
		stream1 << version;
		std::string value( stream1.str() );
	
		std::stringstream stream2;
		std::string::iterator fi = value.begin();
	
		for( ; fi != value.end(); ++fi )
		{
			if( *fi == '.' )
			{
				++fi;
				break;
			}
			stream2 << *fi;
		}
		
		if( fi == value.end() )
		{
			throw_exception( toString( location, *this ) 
				<< "Malformed version number " << value, MalformedVersion );
		}
	
		statement.directive = ir::PTXStatement::Version;
		stream2 >> statement.major;
	
		std::stringstream stream3;
	
		for( ; fi != value.end(); ++fi )
		{
			stream3 << *fi;
		}
	
		if( stream3.str().empty() )
		{
			throw_exception( toString( location, *this ) 
				<< "Malformed version number " << value, MalformedVersion );
		}
	
		stream3 >> statement.minor;

		if(statement.major < 2 )
		{
			throw_exception( toString( location, *this ) 
				<< "Cannot parse PTX version " << statement.major 
				<< "." << statement.minor << " with version 2.1 parser.", 
				NotVersion2_1 );
		}
	}
	
	void PTXParser::State::identifierList( const std::string& identifier )
	{
		report( "  Rule: IDENTIFIER" );
		identifiers.clear();
		report( "   Appending " << identifier << " to list." );
		identifiers.push_back( identifier );
	}

	void PTXParser::State::identifierList2( const std::string& identifier )
	{
		report( "  Rule: identifierList , IDENTIFIER" );
		report( "   Appending " << identifier << " to list." );
		identifiers.push_back( identifier );
	}

	void PTXParser::State::decimalListSingle( long long int value )
	{
		report( "  Rule: DECIMAL_CONSTANT" );
	
		if( statement.array.stride.empty() )
		{
			statement.array.stride.push_back( 1 );
		}
	
		report( "   Appending " << value << " to decimal list.");
		ir::PTXStatement::Data data;
		data.s64 = value;
		statement.array.values.push_back( data );
	}
	
	void PTXParser::State::decimalListSingle2( long long int value )
	{
		report( "  Rule: decimalList ',' DECIMAL_CONSTANT" );
	
		report( "   Appending " << value << " to decimal list.");
		ir::PTXStatement::Data data;
		data.s64 = value;
		statement.array.values.push_back( data );
	}

	void PTXParser::State::floatList( double value )
	{
		report( "  Rule: DOUBLE_CONSTANT" );
	
		if( statement.array.stride.empty() )
		{
			statement.array.stride.push_back( 1 );
		}
	
		report( "   Appending " << value << " to float list.");
		ir::PTXStatement::Data data;
		data.f64 = value;

		statement.array.values.push_back( data );
	}

	void PTXParser::State::floatList1( double value )
	{
		report( "  Rule: floatList ',' DOUBLE_CONSTANT" );
		report( "   Appending " << value << " to float list.");
		ir::PTXStatement::Data data;
		data.f64 = value;
		statement.array.values.push_back( data );
	}
	
	void PTXParser::State::singleList( float value )
	{
		report( "  Rule: DOUBLE_CONSTANT" );
	
		if( statement.array.stride.empty() )
		{
			statement.array.stride.push_back( 1 );
		}
	
		report( "   Appending " << value << " to single list.");
		ir::PTXStatement::Data data;
		data.f64 = value;
		statement.array.values.push_back( data );
	}

	void PTXParser::State::singleList1( float value )
	{
		report( "  Rule: singleList ',' SINGLE_CONSTANT" );
	
		report( "   Appending " << value << " to single list.");
		ir::PTXStatement::Data data;
		data.f64 = value;
		statement.array.values.push_back( data );	
	}
	
	void PTXParser::State::targetElement( int token )
	{
		report( "  Rule: targetOption" );
		if( token == TOKEN_SM10 ) statement.targets.push_back( "sm_10" );
		else if( token == TOKEN_SM11 ) statement.targets.push_back( "sm_11" );
		else if( token == TOKEN_SM12 ) statement.targets.push_back( "sm_12" );
		else if( token == TOKEN_SM13 ) statement.targets.push_back( "sm_13" );
		else if( token == TOKEN_SM20 ) statement.targets.push_back( "sm_20" );
		else if( token == TOKEN_SM21 ) statement.targets.push_back( "sm_21" );
		else if( token == TOKEN_MAP_F64_TO_F32 )
		{
			statement.targets.push_back( "map_f64_to_f32" );
		}
		else
		{
			assertM(false, "Ocelot internal error - invalid token.");
		}
	}
	
	void PTXParser::State::target()
	{
		report( "  Rule: TARGET targetElementList" );
		statement.directive = ir::PTXStatement::Target;
	}
	
	void PTXParser::State::noAddressSpace()
	{
		statement.instruction.addressSpace = ir::PTXInstruction::Generic;
	}
	
	void PTXParser::State::addressSpace( int value )
	{
		statement.instruction.addressSpace = tokenToAddressSpace( value );
	}

	void PTXParser::State::dataType( int value )
	{
		operand.type = tokenToDataType( value );
	}
	
	void PTXParser::State::instructionVectorType( int value )
	{
		statement.instruction.vec = tokenToVec( value );
	}

	void PTXParser::State::statementVectorType( int value )
	{
		statement.array.vec = tokenToVec( value );
	}
	
	void PTXParser::State::attribute( bool visible, bool external )
	{
		assert( !( visible && external ) );
		if( visible )
		{
			statement.attribute = ir::PTXStatement::Visible;
		}
		else if( external )
		{
			statement.attribute = ir::PTXStatement::Extern;
		}
		else
		{
			statement.attribute = ir::PTXStatement::NoAttribute;
		}
	}

	void PTXParser::State::shiftAmount( bool shift )
	{
		statement.instruction.shiftAmount = shift;
	}

	void PTXParser::State::vectorIndex( int token )
	{
		operand.vIndex = tokenToVectorIndex( token );
	}

	void PTXParser::State::arrayDimensionSet( long long int value, 
		YYLTYPE& location, bool add )
	{
		report( "  Rule: '[' DECIMAL_CONSTANT ']'" );

		if( !add )
		{
			statement.array.stride.clear();
		}
		
		if( value <= 0 )
		{
			throw_exception( toString( location, *this ) 
				<< "Invalid array dimension " << value, InvalidArray );
		}
	
		report( "   Got dimension " << value );
		statement.array.stride.push_back( ( unsigned int ) value );
	}

	void PTXParser::State::arrayDimensionSet()
	{
		report( "  Rule: arrayDimensions '[' ']'" );
		statement.array.stride.clear();
	
		report( "   Got dimension " << 0 );
		statement.array.stride.push_back( 0 );
	}
	
	void PTXParser::State::arrayDimensions()
	{
		statement.array.stride.clear();
	}
	
	void PTXParser::State::statementEnd( YYLTYPE& location )
	{
		statement.line   = location.first_line;
		statement.column = location.first_column;		

		report( "   At (" << statement.line << "," << statement.column
			<< ") : Parsed statement " << statements.size() 
			<< " \"" << statement.toString() << "\"" );
		statements.push_back( statement );

		operand = ir::PTXOperand();
		statement.array.values.clear();
		alignment = 1;
		statement.array.vec = ir::PTXOperand::v1;
		statement.instruction.statementIndex = statements.size();
	}
	
	void PTXParser::State::assignment()
	{
		report( "  Clearing doubles" );
		statement.array.values.clear();
	}
	
	void PTXParser::State::registerDeclaration( const std::string& name, 
		YYLTYPE& location, unsigned int regs )
	{
		report( "  Rule: REG dataType IDENTIFIER ';' : " << name 
			<< " ["  << regs << "]" );
		statement.directive = ir::PTXStatement::Reg;
		statement.type = operand.type;
		statement.name = name;
		statement.attribute = ir::PTXStatement::NoAttribute;

		if( operand.type == ir::PTXOperand::pred )
		{
			operand.condition = ir::PTXOperand::Pred;
		}

		statement.array.stride.resize(1);
		statement.array.stride[0] = regs;
		
		operand.vec = statement.array.vec;
		operand.addressMode = ir::PTXOperand::Register;
		
		if( regs == 0 )
		{
			statement.array.stride[0] = 0;
			
			if( operands.count( statement.name ) != 0 ) 
			{
				throw_exception( toString( location, *this ) 
					<< "Variable name " << statement.name 
					<< " already declared in this scope.", 
					DuplicateDeclaration );
			}
			
			if( operand.vec != ir::PTXOperand::v1 )
			{
				operand.array.push_back( ir::PTXOperand( 
					ir::PTXOperand::Register, operand.type, 
					statement.name + ".x" ) );
				operand.array.push_back( ir::PTXOperand( 
					ir::PTXOperand::Register, operand.type, 
					statement.name + ".y" ) );
				if( operand.vec != ir::PTXOperand::v2 ) {
					operand.array.push_back( ir::PTXOperand( 
						ir::PTXOperand::Register, operand.type, 
						statement.name + ".z" ) );
					operand.array.push_back( ir::PTXOperand( 
						ir::PTXOperand::Register, operand.type, 
						statement.name + ".w" ) );
				}
			}
		
			operand.identifier = statement.name;
		
			operands.insert( std::make_pair( statement.name, 
				OperandWrapper( operand, 
				statement.instruction.addressSpace ) ) );
				
			operand.array.clear();
			if( inEntry )
			{
				localOperands.push_back( statement.name );
			}
		}
		
		for( unsigned int i = 0; i < regs; ++i )
		{
			std::stringstream name;
			name << statement.name << i;
	
			if( operands.count( name.str() ) != 0 ) 
			{
				throw_exception( toString( location, *this ) 
					<< "Variable name " << statement.name 
					<< " already declared in this scope.", 
					DuplicateDeclaration );
			}

			operand.identifier = name.str();

			if( operand.vec != ir::PTXOperand::v1 )
			{
				operand.array.push_back( ir::PTXOperand( 
					ir::PTXOperand::Register, operand.type, 
					name.str() + ".x" ) );
				operand.array.push_back( ir::PTXOperand( 
					ir::PTXOperand::Register, operand.type, 
					name.str() + ".y" ) );
				if( operand.vec != ir::PTXOperand::v2 ) {
					operand.array.push_back( ir::PTXOperand( 
						ir::PTXOperand::Register, operand.type, 
						name.str() + ".z" ) );
					operand.array.push_back( ir::PTXOperand( 
						ir::PTXOperand::Register, operand.type, 
						name.str() + ".w" ) );
				}
			}
			
			operands.insert( std::make_pair( name.str(), 
				OperandWrapper( operand, 
				statement.instruction.addressSpace ) ) );
		
			operand.array.clear();
			if( inEntry )
			{
				localOperands.push_back( name.str() );
			}
		}
	}

	void PTXParser::State::registerSeperator( YYLTYPE& location )
	{
		ir::PTXOperand::DataType type = statement.type;
		statementEnd( location );
		operand.type = type;
	}

	void PTXParser::State::initializableDeclaration( const std::string& name, 
		YYLTYPE& one, YYLTYPE& two )
	{
		report( "  Rule: initializable addressableVariablePrefix IDENTIFIER " 
			<< "arrayDimensions initializer ';'" );

		assert( directive == ir::PTXStatement::Const 
			|| directive == ir::PTXStatement::Global 
			|| directive == ir::PTXStatement::Shared
			|| directive == ir::PTXStatement::Local);

		statement.directive = directive;
		report( "   Name = " << name );
		statement.name = name;
		statement.alignment = alignment;
		statement.type = operand.type;
	
		// correct for single precision
		if( statement.type == ir::PTXOperand::f32 )
		{
			for( ir::PTXStatement::ArrayVector::iterator 
				fi = statement.array.values.begin();
				fi != statement.array.values.end(); ++fi )
			{
				fi->f32 = (float) fi->f64;			
			}	
		}
	
		if( statement.array.values.size() != 0 )
		{
			unsigned int expected = 0;
	
			for( ir::PTXStatement::ArrayStrideVector::iterator 
				fi = statement.array.stride.begin(); 
				fi != statement.array.stride.end(); ++fi )
			{
				expected += *fi;
			}
		
			if( statement.array.vec == ir::PTXOperand::v2 )
			{
				expected *= 2;
			} 
			else if( statement.array.vec == ir::PTXOperand::v4 )
			{
				expected *= 4;
			}
		
			if( expected != statement.array.values.size() )
			{
				throw_exception( toString( two, *this ) 
					<< "Array size " << expected 
					<< " does not match initializer size " 
					<< statement.array.values.size(), 
					InitializerSizeMismatch );
			}
		}
		
		if( operands.count( statement.name ) != 0 ) 
		{
			throw_exception( toString( one, *this ) 
				<< "Variable name " << statement.name 
				<< " already declared in this scope.", 
				DuplicateDeclaration );
		}

		operand.identifier = statement.name;
		operand.addressMode = ir::PTXOperand::Address;
		operands.insert( std::make_pair( statement.name, 
			OperandWrapper( operand, _toAddressSpace( directive ) ) ) );
	
		if( inEntry )
		{
			localOperands.push_back( statement.name );
		}
	}

	void PTXParser::State::textureDeclaration( int space, 
		const std::string& name, YYLTYPE& location )
	{
		report( "  Rule: textureSpace TOKEN_TEXREF identifier ';'" );

		statement.directive = ir::PTXStatement::Texref;
		statement.space = tokenToTextureSpace( space );
		statement.name = name;

		if( operands.count( statement.name ) != 0 ) 
		{
			throw_exception( toString( location, *this ) 
				<< "Texture reference name " << statement.name 
				<< " already declared in this scope.", 
				DuplicateDeclaration );
		}
	
		operand.identifier = statement.name;
		operand.addressMode = ir::PTXOperand::Address;
		operands.insert( std::make_pair( statement.name, 
			OperandWrapper( operand, _toAddressSpace( directive ) ) ) );
	}

	void PTXParser::State::surfaceDeclaration( int space, 
		const std::string &name, YYLTYPE &location)
	{
		report( "  Rule: textureSpace TOKEN_SURFREF identifier ';'" );

		statement.directive = ir::PTXStatement::Surfref;
		statement.space = tokenToTextureSpace( space );
		statement.name = name;

		if( operands.count( statement.name ) != 0 ) 
		{
			throw_exception( toString( location, *this ) 
				<< "Texture reference name " << statement.name 
				<< " already declared in this scope.", 
				DuplicateDeclaration );
		}
	
		operand.identifier = statement.name;
		operand.addressMode = ir::PTXOperand::Address;
		operands.insert( std::make_pair( statement.name, 
			OperandWrapper( operand, _toAddressSpace( directive ) ) ) );
	}
	
	void PTXParser::State::samplerDeclaration( int space,
		const std::string &name, YYLTYPE &location)
	{
		report( "  Rule: textureSpace TOKEN_SURFREF identifier ';'" );

		statement.directive = ir::PTXStatement::Surfref;
		statement.space = tokenToTextureSpace( space );
		statement.name = name;

		if( operands.count( statement.name ) != 0 ) 
		{
			throw_exception( toString( location, *this ) 
				<< "Texture reference name " << statement.name 
				<< " already declared in this scope.", 
				DuplicateDeclaration );
		}
	
		operand.identifier = statement.name;
		operand.addressMode = ir::PTXOperand::Address;
		operands.insert( std::make_pair( statement.name, 
			OperandWrapper( operand, _toAddressSpace( directive ) ) ) );
	}

	void PTXParser::State::argumentDeclaration( const std::string& name, 
		YYLTYPE& location )
	{
		report( "  Rule: argument addressableVariablePrefix identifier " 
			<< " arrayDimensions" );

		assert( inEntry || inArgumentList || inReturnList );
	
		statement.directive = ir::PTXStatement::Param;
		statement.name = name;
		statement.alignment = alignment;
		statement.type = operand.type;

		operand.identifier = statement.name;
		operand.addressMode = ir::PTXOperand::Address;
		
		if( operands.count( statement.name ) != 0 )
		{
			throw_exception( toString( location, *this ) 
				<< "Argument operand " << statement.name 
				<< " already declared in this scope.", 
				DuplicateDeclaration );
		}

		operands.insert( std::make_pair( statement.name, 
			OperandWrapper( operand, ir::PTXInstruction::Param ) ) );

		localOperands.push_back( statement.name );

		if( inReturnList )
		{
			prototype.returnTypes.push_back( operand.type );
		}
		else if( inArgumentList )
		{
			prototype.argumentTypes.push_back( operand.type );
		}

		statementEnd( location );
	}

	void PTXParser::State::fileDeclaration( unsigned int file, 
		const std::string& name )
	{
		report( "  Rule: TOKEN_FILE DECIMAL_CONSTANT TOKEN_STRING: .file " 
			<< file << " " << name );
		statement.directive = ir::PTXStatement::File;
		statement.name = name;
		statement.sourceFile = file;
	}

	void PTXParser::State::openBrace( YYLTYPE& location )
	{
		report( "  Rule: '{'" );

		assert( !inEntry );
		inEntry = true;

		statement.directive = ir::PTXStatement::StartScope;	
		
		statementEnd( location );
	}
	
	void PTXParser::State::closeBrace( YYLTYPE& location )
	{
		report( "  Rule: '}'" );

		assert( inEntry );
		inEntry = false;

		statement.directive = ir::PTXStatement::EndScope;	
		statementEnd( location );
	
		for( StringList::iterator operand = localOperands.begin(); 
			operand != localOperands.end(); ++operand )
		{
			report( "   Local variable " << *operand << " went out of scope" );
			OperandMap::iterator fi = operands.find( *operand );
			assert( fi != operands.end() );
			operands.erase( fi );
		}
	
		localOperands.clear();
	}

	void PTXParser::State::argumentListBegin( YYLTYPE& location )
	{
		report( "  Rule: '('" );
		assert( !inArgumentList );
		inArgumentList = true;
		
		statement.directive = ir::PTXStatement::StartParam;
		
		statementEnd( location );
	}

	void PTXParser::State::argumentListEnd( YYLTYPE& location )
	{
		report( "  Rule: ')'" );
		assert( inArgumentList );
		inArgumentList = false;

		statement.directive = ir::PTXStatement::EndParam;
	
		statementEnd( location );		
	}

	void PTXParser::State::returnArgumentListBegin( YYLTYPE& location )
	{
		report( "  Rule: '('" );
		assert( !inReturnList );
		inReturnList = true;

		statement.directive = ir::PTXStatement::StartParam;
	
		statementEnd( location );
	}

	void PTXParser::State::returnArgumentListEnd( YYLTYPE& location )
	{
		report( "  Rule: ')'" );
		assert( inReturnList );
		inReturnList = false;

		statement.directive = ir::PTXStatement::EndParam;
	
		statementEnd( location );		
	}

	void PTXParser::State::functionBegin( YYLTYPE& location )
	{
		report( "  Rule: .func" );
		statement.directive = ir::PTXStatement::Func;
		
		statementEnd( location );
	}

	void PTXParser::State::functionName( const std::string& name, 
		YYLTYPE& location )
	{
		report( "  Rule functionName : identifier" );

		statement.directive = ir::PTXStatement::FunctionName;
		statement.name = name;
		prototype.name = name;
		
		statementEnd( location );
	}

	void PTXParser::State::functionDeclaration( YYLTYPE& location, bool body )
	{
		report( "  Rule: externOrVisible functionBegin " << 
			"optionalReturnArgumentList identifier argumentList" );
		
		if( !body )
		{
			if( prototypes.count( prototype.name ) != 0 )
			{
				throw_exception( toString( location, *this ) 
					<< "Function/Kernel " << prototype.name 
					<< " already declared in this scope.", 
					DuplicateDeclaration );
			}
		
			for( StringList::iterator operand = localOperands.begin(); 
				operand != localOperands.end(); ++operand )
			{
				report( "   Local variable " << *operand 
					<< " went out of scope" );
				OperandMap::iterator fi = operands.find( *operand );
				assert( fi != operands.end() );
				operands.erase( fi );
			}
	
			localOperands.clear();
			
			statement.directive = ir::PTXStatement::EndFuncDec;
			statementEnd( location );
		}

		PrototypeMap::iterator proto = prototypes.find( prototype.name );
		if( proto != prototypes.end() )
		{
			if( !proto->second.compare( prototype ) )
			{
				throw_exception( toString( location, *this ) 
					<< "Function/Kernel " << prototype.name 
					<< " already declared in this scope with " 
					<< "different arguments.\nHere: " 
					<< prototype.toString() << "\nPrevious:" 
					<< proto->second.toString(), 
					DuplicateDeclaration );
			}
		}
		else
		{
			prototypes.insert( std::make_pair( 
				prototype.name, prototype ) );
			operands.insert( std::make_pair( prototype.name, 
				ir::PTXOperand( ir::PTXOperand::FunctionName, 
				ir::PTXOperand::TypeSpecifier_invalid, prototype.name ) ) );
		}
		
		prototype.clear();
	}

	void PTXParser::State::entry( const std::string& name, YYLTYPE& location )
	{
		report( "  Rule: ENTRY identifier" );

		statement.directive = ir::PTXStatement::Entry;
		statement.name = name;
	
		prototype.name = name;
	
		statementEnd( location );
	}	
	
	void PTXParser::State::entryDeclaration( YYLTYPE& location )
	{
		report( "  Rule: entryName argumentList performanceDirectives" );
	
		if( prototypes.count( statement.name ) != 0 )
		{
			throw_exception( toString( location, *this ) 
				<< "Function/Kernel " << statement.name 
				<< " already declared in this scope.", 
				DuplicateDeclaration );
		}

		prototypes.insert( std::make_pair( prototype.name, prototype ) );
		
		prototype.clear();
	}
	
	void PTXParser::State::entryStatement( YYLTYPE& location )
	{
		statementEnd( location );
	
		report( "  Rule: guard instruction : " 
			<< statements.back().instruction.toString() );
	
		// check for an error
		assert( !statements.empty() );
		assert( statements.back().directive == ir::PTXStatement::Instr );
	
		std::string message = 
			statements.back().instruction.valid();
	
		if( message != "" )
		{
			throw_exception( toString( location, *this ) 
				<< "Parsed invalid instruction " 
				<< statements.back().instruction.toString() 
				<< " : " << message, InvalidInstruction );
		}
	
		operandVector.clear();
	}

	void PTXParser::State::locationAddress( int token )
	{
		directive = tokenToDirective( token );
		operand.addressMode = ir::PTXOperand::Address;
		operand.offset = 0;
	}
	
	void PTXParser::State::uninitializableDeclaration( const std::string& name )
	{
		report( "  Rule: uninitializable addressableVariablePrefix IDENTIFIER " 
			<< "arrayDimensions';' : " << name );

		assert( directive == ir::PTXStatement::Param || 
			directive == ir::PTXStatement::Local ||
			directive == ir::PTXStatement::Shared );

		statement.directive = directive;
		statement.name = name;
		statement.alignment = alignment;
		statement.type = operand.type;
		statement.array.stride.assign( 
			statement.array.stride.begin(), 
			statement.array.stride.end() );
	
		operand.identifier = statement.name;
		operand.addressMode = ir::PTXOperand::Address;
	
		operands.insert( std::make_pair( 
			statement.name, OperandWrapper( operand, 
			_toAddressSpace( directive ) ) ) );
		
		if( inEntry )
		{
			localOperands.push_back( statement.name );
		}
	}

	void PTXParser::State::location( long long int one, long long int two, 
		long long int three )
	{
		report( "  Rule: LOC DECIMAL_CONSTANT DECIMAL_CONSTANT " 
			<< "DECIMAL_CONSTANT : " << one << ", " << two << ", " << three );

		std::stringstream stream;
	
		stream << one << " " << two << " " << three;

		statement.directive = ir::PTXStatement::Loc;
		statement.sourceFile = (unsigned int) one;
		statement.sourceLine = (unsigned int) two;
		statement.sourceColumn = (unsigned int) three;
		
		statement.name = stream.str();
	}
	
	void PTXParser::State::label( const std::string& string )
	{
		report( "  Rule: LABEL : " << string );

		statement.directive = ir::PTXStatement::Label;
		statement.name = string;
	}

	void PTXParser::State::pragma( const std::string& string )
	{
		report( "  Rule: PRAGMA : " << string );

		statement.directive = ir::PTXStatement::Pragma;
		statement.name = string;
	}
	
	void PTXParser::State::labelOperand( const std::string& string )
	{
		OperandMap::iterator mode = operands.find( string );
		
		if( mode == operands.end() )
		{
			operand.identifier = string;
			operand.addressMode = ir::PTXOperand::Label;
			operand.type = ir::PTXOperand::TypeSpecifier_invalid;
		}
		else
		{
			if( mode->second.operand.addressMode == ir::PTXOperand::Address )
			{
				statement.instruction.addressSpace = mode->second.space;
			}	
			operand = mode->second.operand;
		}
	
		operandVector.push_back( operand );
	}
	
	void PTXParser::State::nonLabelOperand( const std::string& string, 
		YYLTYPE& location, bool invert )
	{
		OperandMap::iterator mode = operands.find( string );
		
		if( mode == operands.end() )
		{
			throw_exception( toString( location, *this ) << "Operand " 
				<< string << " not declared in this scope.", NoDeclaration );
		}

		if( mode->second.operand.addressMode == ir::PTXOperand::Address )
		{
			statement.instruction.addressSpace = mode->second.space;
			operand = mode->second.operand;
		}
		else if( mode->second.operand.addressMode == ir::PTXOperand::Register
			|| mode->second.operand.addressMode == ir::PTXOperand::Special )
		{
			if( mode->second.operand.vec != ir::PTXOperand::v1 )
			{
				switch( operand.vIndex )
				{
					case ir::PTXOperand::ix:
					{
						operand = mode->second.operand.array[ 0 ];
						break;
					}
					case ir::PTXOperand::iy:
					{
						operand = mode->second.operand.array[ 1 ];
						break;
					}
					case ir::PTXOperand::iz:
					{
						operand = mode->second.operand.array[ 2 ];
						break;
					}
					case ir::PTXOperand::iw:
					{
						operand = mode->second.operand.array[ 3 ];
						break;
					}
					default:
					{
						operand = mode->second.operand;
						break;
					}
				}
			}
			else
			{
				operand = mode->second.operand;
			}
		}
		else if( mode->second.operand.addressMode 
			== ir::PTXOperand::FunctionName ) {
			operand = mode->second.operand;
		}
		
		if( invert )
		{
			if( operand.type != ir::PTXOperand::pred )
			{
				throw_exception( toString( location, *this ) << "Operand " 
					<< string << " is not a predicate and can't be inverted.", 
					NotPredicate );
			}
			operand.condition = ir::PTXOperand::InvPred;
		}
	
		operandVector.push_back( operand );		
	}
			
	void PTXParser::State::constantOperand( long long int value )
	{
		operand.addressMode = ir::PTXOperand::Immediate;
		operand.imm_int = value;
		operand.vec = ir::PTXOperand::v1;
		operand.type = smallestType( operand.imm_int );
		operandVector.push_back( operand );	
	}
	
	void PTXParser::State::constantOperand( unsigned long long int value )
	{
		operand.addressMode = ir::PTXOperand::Immediate;
		operand.imm_int = value;
		operand.vec = ir::PTXOperand::v1;
		operand.type = smallestType( operand.imm_uint );
		operandVector.push_back( operand );
	}
	
	void PTXParser::State::constantOperand( float value )
	{
		operand.addressMode = ir::PTXOperand::Immediate;
		operand.imm_float = value;
		operand.vec = ir::PTXOperand::v1;
		operand.type = ir::PTXOperand::f32;	
		operandVector.push_back( operand );
	}

	void PTXParser::State::constantOperand( double value )
	{
		operand.addressMode = ir::PTXOperand::Immediate;
		operand.imm_float = value;
		operand.vec = ir::PTXOperand::v1;
		operand.type = ir::PTXOperand::f64;
		operandVector.push_back( operand );
	}
	
	void PTXParser::State::indexedOperand( const std::string& name, 
		YYLTYPE& location, long long int index )
	{
		OperandMap::iterator mode = operands.find( name );
		
		if( mode == operands.end() )
		{
			throw_exception( toString( location, *this ) << "Operand " 
				<< name << " not declared in this scope.", NoDeclaration );
		}

		operand.addressMode = ir::PTXOperand::Address;
	
		operand.identifier = name;
		operand.vec = ir::PTXOperand::v1;
		operand.array.clear();

		operand.offset = (int) index * ir::PTXOperand::bytes(
			mode->second.operand.type);
		operand.type = mode->second.operand.type;
	
		operandVector.push_back( operand );	
	}

	
	void PTXParser::State::addressableOperand( const std::string& name, 
		long long int value, YYLTYPE& location, bool invert )
	{
		OperandMap::iterator mode = operands.find( name );
		
		if( mode == operands.end() )
		{
			throw_exception( toString( location, *this ) << "Operand " 
				<< name << " not declared in this scope.", NoDeclaration );
		}
		else
		{
			if( mode->second.operand.addressMode == ir::PTXOperand::Register )
			{
				operand.addressMode = ir::PTXOperand::Indirect;
			}
			else
			{
				operand.addressMode = ir::PTXOperand::Address;
			}
		}
	
		operand.identifier = name;
		operand.vec = ir::PTXOperand::v1;
		operand.array.clear();

		if( invert )
		{ 
			value = -value;
		}
		operand.offset = (int) value;
		operand.type = mode->second.operand.type;
	
		operandVector.push_back( operand );
	}

	void PTXParser::State::arrayOperand( YYLTYPE& location )
	{
		assert( !identifiers.empty() );

		OperandMap::iterator mode = operands.find( identifiers.front() );
	
		if( identifiers.size() > 4 )
		{
			throw_exception( toString( location, *this ) 
				<< "Array operand \"" 
				<< hydrazine::toString( identifiers.begin(), 
				identifiers.end(), "," ) 
				<< "\" has more than 4 elements.", InvalidArray );
		}

#if 0
		// I don't think this is a valid check
		if( identifiers.size() == 3 )
		{
			throw_exception( toString( location, *this ) 
				<< "Array operand \"" 
				<< hydrazine::toString( identifiers.begin(), 
				identifiers.end(), "," ) 
				<< "\" has exactly 3 elements.", InvalidArray );
		}
#endif
	
		if( mode == operands.end() )
		{
			throw_exception( toString( location, *this ) << "Operand " 
				<< identifiers.front() << " not declared in this scope.", 
				NoDeclaration );
		}
		
		operand = mode->second.operand;
	
		if( identifiers.size() == 1 )
		{
			operand.vec = ir::PTXOperand::v1;
		
			operand.array.push_back( mode->second.operand );
		}
		else if( identifiers.size() >= 2 )
		{
			operand.vec = ir::PTXOperand::v2;
			operand.array.push_back( mode->second.operand );
		
			mode = operands.find( identifiers[1] );
		
			if( mode == operands.end() )
			{
				throw_exception( toString( location, *this ) << "Operand " 
					<< identifiers[1] << " not declared in this scope.", 
					NoDeclaration );
			}
				
			operand.array.push_back( mode->second.operand );
		}
	
		if( identifiers.size() == 4 )
		{
	
			operand.vec = ir::PTXOperand::v4;
		
			mode = operands.find( identifiers[2] );
		
			if( mode == operands.end() )
			{
				throw_exception( toString( location, *this ) << "Operand " 
					<< identifiers[2] << " not declared in this scope.", 
					NoDeclaration );
			}
		
			operand.array.push_back( mode->second.operand );
		
			mode = operands.find( identifiers[3] );
		
			if( mode == operands.end() )
			{
				throw_exception( toString( location, *this ) << "Operand " 
					<< identifiers[3] << " not declared in this scope.", 
					NoDeclaration );
			}

			operand.array.push_back( mode->second.operand );
		}
	
		operandVector.push_back( operand );
		operand.array.clear();
	}

	void PTXParser::State::returnOperand()
	{
		++returnOperands;
	}

	void PTXParser::State::guard( const std::string& name, YYLTYPE& location, 
		bool invert )
	{
		report( "  Rule: PREDICATE_IDENTIFIER : " << name  );

		OperandMap::iterator mode = operands.find( name );
	
		if( mode == operands.end() )
		{
			throw_exception( toString( location, *this ) << "Predciate " 
				<< name << " not declared in this scope.", NoDeclaration );
		}

		operand = mode->second.operand;
		if( invert )
		{
			operand.condition = ir::PTXOperand::InvPred;
		}
		else
		{
			operand.condition = ir::PTXOperand::Pred;
		}
		
		if( mode->second.operand.addressMode == ir::PTXOperand::Address )
		{
			statement.instruction.addressSpace = mode->second.space;
		}
		
		operandVector.push_back( operand );
	}

	void PTXParser::State::guard()
	{
		report( "  Rule: No guard predicate" );
		operand.addressMode = ir::PTXOperand::Register;
		operand.type = ir::PTXOperand::pred;
		operand.condition = ir::PTXOperand::PT;
		operandVector.push_back( operand );
	}

	void PTXParser::State::tail( bool condition )
	{
		statement.instruction.tailCall = condition;
	}
	
	void PTXParser::State::uni( bool condition )
	{
		statement.instruction.uni = condition;
	}

	void PTXParser::State::carry( bool condition )
	{
		if( condition )
		{
			report( "  Rule: Carry" );
			statement.instruction.carry = ir::PTXInstruction::CC; 		
			statement.instruction.pq.type = ir::PTXOperand::u32;
			statement.instruction.pq.addressMode = ir::PTXOperand::Register;
			statement.instruction.pq.vec = ir::PTXOperand::v1;
			statement.instruction.pq.identifier = "%_ZconditionCode";
		}
		else
		{
			report( "  Rule: No Carry" );
			statement.instruction.carry = ir::PTXInstruction::None;
		}
	}

	void PTXParser::State::full()
	{
		statement.instruction.divideFull = true;
	}

	void PTXParser::State::modifier( int token )
	{
		statement.instruction.modifier |= tokenToModifier( token );
	}

	void PTXParser::State::atomic( int token )
	{
		statement.instruction.atomicOperation = tokenToAtomicOperation( token );
	}

	void PTXParser::State::volatileFlag( bool condition )
	{
		if( condition )
		{
			statement.instruction.volatility = ir::PTXInstruction::Volatile;
		}
		else
		{
			statement.instruction.volatility = ir::PTXInstruction::Nonvolatile;
		}
	}
	
	void PTXParser::State::reduction( int token )
	{
		statement.instruction.reductionOperation 
			= tokenToReductionOperation( token );
	}
	
	void PTXParser::State::comparison( int token )
	{
		statement.instruction.comparisonOperator = tokenToCmpOp( token );
	}

	void PTXParser::State::boolean( int token )
	{
		statement.instruction.booleanOperator = tokenToBoolOp( token );
	}

	void PTXParser::State::geometry( int token )
	{
		statement.instruction.geometry = tokenToGeometry( token );
	}

	void PTXParser::State::vote( int token )
	{
		statement.instruction.vote = tokenToVoteMode( token );
	}
	
	void PTXParser::State::level( int token )
	{
		statement.instruction.level = tokenToLevel( token );
	}
	
	void PTXParser::State::permute( int token )
	{
		statement.instruction.permuteMode = tokenToPermuteMode( token );
	}
	
	void PTXParser::State::floatingPointMode( int token )
	{
		statement.instruction.floatingPointMode
			= tokenToFloatingPointMode( token );
	}
	
	void PTXParser::State::defaultPermute()
	{
		statement.instruction.permuteMode = ir::PTXInstruction::DefaultPermute;
	}

	void PTXParser::State::instruction()
	{
		statement.instruction = ir::PTXInstruction( );
		statement.instruction.statementIndex = statements.size();
	}

	void PTXParser::State::instruction( const std::string& opcode,
		int dataType )
	{
		
		_setImmediateTypes();

		statement.directive = ir::PTXStatement::Instr;
		statement.instruction.type = tokenToDataType( dataType );
		statement.instruction.opcode = stringToOpcode( opcode );
		statement.instruction.pg = operandVector[0];

		unsigned int index = 1;
				
		if( operandVector.size() > index )
		{
			statement.instruction.d = operandVector[index++];
		}

		if( operandVector.size() > index )
		{
			if( ( operandVector[ index ].type == ir::PTXOperand::pred
				&& operandVector.size() > 4 ) || operandVector.size() == 6 )
			{
				statement.instruction.pq = operandVector[index++];
			}
		}

		if( operandVector.size() > index )
		{
			statement.instruction.a = operandVector[index++];
		}
		if( operandVector.size() > index )
		{
			statement.instruction.b = operandVector[index++];
		}
		if( operandVector.size() > index )
		{
			statement.instruction.c = operandVector[index++];
		}
	}
	
	void PTXParser::State::instruction( const std::string& opcode )
	{
		instruction( opcode, TOKEN_B64 );
	}

	void PTXParser::State::tex( int dataType )
	{
		report( "  Rule: instruction : tex" );

		assert( operandVector.size() == 4 );

		statement.directive          = ir::PTXStatement::Instr;
		statement.instruction.type   = tokenToDataType( dataType );
		statement.instruction.opcode = stringToOpcode( "tex" );
		statement.instruction.pg     = operandVector[0];
		statement.instruction.d      = operandVector[1];
		statement.instruction.a      = operandVector[2];
		statement.instruction.c      = operandVector[3];		
	}
	
	void PTXParser::State::callPrototypeName( const std::string& identifier )
	{
		report( "  Rule: callPrototypeName" );
		prototype.name = identifier;
	}
					
	void PTXParser::State::call( const std::string& identifier, 
		YYLTYPE& location )
	{
		report( "  Rule: instruction : call" );
	
		statement.directive = ir::PTXStatement::Instr;
		statement.instruction.opcode = stringToOpcode( "call" );
		
		statement.instruction.pg = operandVector[0];
		
		OperandMap::iterator operand = operands.find( identifier );

		if( operand == operands.end() )
		{
			throw_exception( toString( location, *this ) << "Operand '" 
				<< identifier << "' not declared in this scope.", 
				InvalidInstruction );
		}
		
		statement.instruction.a = operand->second.operand;
	
		statement.instruction.d.addressMode = ir::PTXOperand::ArgumentList;
		statement.instruction.b.addressMode = ir::PTXOperand::ArgumentList;

		FunctionPrototype proto;
		
		unsigned int operandIndex = 1;
		for( ; returnOperands > 0; --returnOperands, ++operandIndex )
		{
			statement.instruction.d.array.push_back( 
				operandVector[ operandIndex ] );
			proto.returnTypes.push_back( operandVector[ operandIndex ].type );
		}
		
		for( ; operandIndex < operandVector.size(); ++operandIndex )
		{
			statement.instruction.b.array.push_back(
				operandVector[ operandIndex ] );
			proto.argumentTypes.push_back( operandVector[ operandIndex ].type );
		}
		
		if( statement.instruction.a.addressMode == ir::PTXOperand::Register )
		{
			statement.instruction.c.addressMode = ir::PTXOperand::FunctionName;
			statement.instruction.c.identifier  = prototype.name;
		}
		else
		{
			prototype.name = statement.instruction.a.identifier;
		}
		
		PrototypeMap::iterator pi = prototypes.find( prototype.name );
		if( pi == prototypes.end() )
		{
			throw_exception( toString( location, *this ) 
				<< "Function/Prototype '" 
				<< statement.instruction.a.identifier 
				<< "' not declared in this scope.", 
				NoDeclaration );	
		}
		
		if( !pi->second.compare( proto ) )
		{
			throw_exception( toString( location, *this ) 
				<< " Call instruction '" << statement.instruction.toString() 
				<< "' does not match prototype '" 
				<< pi->second.toString() << "'.", PrototypeMismatch );
		}
		
		prototype.clear();
	}
		
	void PTXParser::State::carryIn()
	{
		ir::PTXOperand conditionCode( ir::PTXOperand::Register, 
			ir::PTXOperand::u32 );
		conditionCode.identifier = "%_ZconditionCode";
		operandVector.push_back( conditionCode );
	}

	void PTXParser::State::relaxedConvert( int token, YYLTYPE& location )
	{
		if( !ir::PTXOperand::relaxedValid( tokenToDataType( token ),
			statement.instruction.a.type ) )
		{
			throw_exception( parser::PTXParser::toString( location, *this ) 
				<< "Type of " << statement.instruction.a.identifier << " " 
				<< ir::PTXOperand::toString( statement.instruction.a.type ) 
				<< " not convertable to type " 
				<< ir::PTXOperand::toString( tokenToDataType( token ) ) 
				<< " using relaxed conversion rules.", InvalidDataType );
		}
	
		statement.instruction.a.type = tokenToDataType( token );
	}
	
	void PTXParser::State::cvtaTo(int token, YYLTYPE& location) {
		statement.instruction.toAddrSpace = true;
	}

	void PTXParser::State::convert( int token, YYLTYPE& location )
	{
		if( !ir::PTXOperand::valid( tokenToDataType( token ),
			statement.instruction.a.type ) )
		{
			throw_exception( parser::PTXParser::toString( location, *this ) 
				<< "Type of " << statement.instruction.a.identifier << " " 
				<< ir::PTXOperand::toString( statement.instruction.a.type ) 
				<< " not convertable to type " 
				<< ir::PTXOperand::toString( tokenToDataType( token ) ) 
				<< " .", InvalidDataType );
		}
	
		statement.instruction.a.type = tokenToDataType( token );
	}

	void PTXParser::State::convertC( int token, YYLTYPE& location )
	{
		if( !ir::PTXOperand::valid( tokenToDataType( token ),
			statement.instruction.c.type ) )
		{
			throw_exception( parser::PTXParser::toString( location, *this ) 
				<< "Type of " << statement.instruction.c.identifier << " " 
				<< ir::PTXOperand::toString( statement.instruction.c.type ) 
				<< " not convertable to type " 
				<< ir::PTXOperand::toString( tokenToDataType( token ) ) 
				<< " .", InvalidDataType );
		}
	
		statement.instruction.c.type = tokenToDataType( token );
	}

	void PTXParser::State::convertD( int token, YYLTYPE& location )
	{
		if( !ir::PTXOperand::valid( tokenToDataType( token ),
			statement.instruction.d.type ) )
		{
			throw_exception( parser::PTXParser::toString( location, *this ) 
				<< "Type of " << statement.instruction.d.identifier << " " 
				<< ir::PTXOperand::toString( statement.instruction.d.type ) 
				<< " not convertable to type " 
				<< ir::PTXOperand::toString( tokenToDataType( token ) ) 
				<< " .", InvalidDataType );
		}
	
		statement.instruction.d.type = tokenToDataType( token );
	}
	
	void PTXParser::State::cacheOperation(int token) {
		statement.instruction.cacheOperation = tokenToCacheOperation(token);
	}
	
	void PTXParser::State::clampOperation(int token) {
		statement.instruction.clamp = tokenToClampOperation(token);
	}
	
	void PTXParser::State::barrierOperation( int token, YYLTYPE & location) {
		statement.instruction.barrierOperation = tokenToBarrierOp(token);
	}
	
	void PTXParser::State::formatMode(int token) {
		statement.instruction.formatMode = tokenToFormatMode(token);
	}
	
	void PTXParser::State::surfaceQuery(int token) {
		report("surfaceQuery(" << token << ")");
		statement.instruction.surfaceQuery = tokenToSurfaceQuery(token);
	}

	void PTXParser::State::returnType( int token )
	{
		report( "  Rule returnType: dataTypeId identifier" );
	
		prototype.returnTypes.push_back( tokenToDataType( token ) );
	}
	
	void PTXParser::State::argumentType( int token )
	{
		report( "  Rule argumentType: dataTypeId identifier" );
	
		prototype.argumentTypes.push_back( tokenToDataType( token ) );
	}
	
	void PTXParser::State::callPrototype( const std::string& name, 
		YYLTYPE& location )
	{
		report( "  Rule callPrototype: TOKEN_LABEL TOKEN_CALL_PROTOTYPE " 
			<< "returnTypeList identifier argumentTypeList ';'" );
			
		prototype.name = name;
			
		if( !prototypes.insert( std::make_pair( name, prototype ) ).second )
		{
			throw_exception( toString( location, *this ) 
				<< "Function/Kernel prototype " << statement.name 
				<< " already declared in this scope.", 
				DuplicateDeclaration );
		}
	
		operands.insert( std::make_pair( name, 
			ir::PTXOperand( ir::PTXOperand::FunctionName, 
			ir::PTXOperand::TypeSpecifier_invalid, name ) ) );
	
		localPrototypes.push_back( name );
		localOperands.push_back( name );
	
		statement.directive     = ir::PTXStatement::FunctionPrototype;
		statement.returnTypes   = prototype.returnTypes;
		statement.argumentTypes = prototype.argumentTypes;
		statement.name          = prototype.name;
		
		prototype.clear();
	}
	
	void PTXParser::State::callTargets( const std::string& name, 
		YYLTYPE& location )
	{
		report( "  Rule: TOKEN_LABEL TOKEN_CALL_TARGETS stringList ';'" );
		statement.directive = ir::PTXStatement::CallTargets;
		statement.targets.assign( identifiers.begin(), identifiers.end() );
		
		// check the targets to make sure that they exist
		for( StringList::iterator target = identifiers.begin(); 
			target != identifiers.end(); ++target )
		{
			if( prototypes.count( *target ) == 0 )
			{
				throw_exception( parser::PTXParser::toString( location, *this ) 
					<< "Function named '" << *target 
					<< "' not declared in this scope.", NoDeclaration );
			}
		}
		
		identifiers.clear();
	}
}

namespace parser
{

	const char* PTXParser::Exception::what() const throw()
	{
		return message.c_str();
	}

	PTXParser::Exception::~Exception() throw()
	{
	}

	std::string PTXParser::toString( YYLTYPE& location, State& state )
	{
		std::stringstream stream;
		stream << state.fileName << " (" << location.first_line << ", " 
			<< location.first_column << "): ";
		return stream.str();
	}

	void PTXParser::checkLabels()
	{
		typedef std::unordered_map< std::string, ir::PTXStatement > 
			StatementMap;
		
		report( "Checking labels." );
		
		StatementMap labels;
		
		ir::Module::StatementVector::iterator 
			begin = state.statements.begin();
		
		for( ir::Module::StatementVector::iterator 
			statement = state.statements.begin(); 
			statement != state.statements.end(); ++statement )
		{
			if( statement->directive == ir::PTXStatement::Label )
			{
				report( " Found label " << statement->name );
			
				StatementMap::iterator label = 
					labels.find( statement->name );
				
				if( label != labels.end() )
				{
					std::stringstream error;
					error << state.fileName << " ("  << statement->line << "," 
						<< statement->column << "): Duplicate label "
						<< statement->name << " previously defined at (" 
						<< label->second.line << "," << label->second.column 
						<< ")";
						
					Exception exception;
					exception.message = error.str();
					exception.error = State::DuplicateLabel;
					throw exception;
				}
				
				labels.insert( std::make_pair( statement->name, *statement ) );
			}
			else if( statement->directive == ir::PTXStatement::EndScope )
			{
				for( ir::Module::StatementVector::iterator 
					s = begin; s != statement; ++s )
				{
					if( s->directive == ir::PTXStatement::Instr )
					{
						ir::PTXOperand* operands[] = { &s->instruction.a, 
							&s->instruction.b, &s->instruction.c, 
							&s->instruction.d };
				
						for( unsigned int i = 0; i < 4; ++i )
						{
							ir::PTXOperand& operand = *operands[ i ];
				
							if( operand.addressMode == ir::PTXOperand::Label )
							{
								StatementMap::iterator label = 
									labels.find( operand.identifier );
				
								if( label == labels.end() )
								{
									std::stringstream error;
									error << state.fileName << " ("  
										<< s->line << "," << s->column 
										<< "): Label "
										<< operand.identifier 
										<< " not delcared in this scope";
						
									Exception exception;
									exception.message = error.str();
									exception.error = State::NoLabel;
									throw exception;
								}
							}
						}
					}
				}
				
				labels.clear();
				begin = statement;
			}
		}	
	}
	
	void PTXParser::reset()
	{
		state.inEntry = false;
		state.inReturnList = false;
		state.inArgumentList = false;
		state.identifiers.clear();

		state.operands.clear();
		state.localOperands.clear();
		state.operandVector.clear();

		state.returnOperands = 0;

		state.statements.clear();
		state.fileName = fileName;

		state.prototypes.clear();
		state.localPrototypes.clear();
		
		ir::PTXOperand bucket;
		bucket.identifier = "_";
		bucket.type = ir::PTXOperand::b64;
		bucket.addressMode = ir::PTXOperand::Register;
		bucket.vec = ir::PTXOperand::v1;
		
		state.operands.insert( std::make_pair( "_", 
			State::OperandWrapper( bucket, 
			ir::PTXInstruction::Global ) ) );
		
		state.addSpecialRegisters();	
	}

	ir::PTXOperand::DataType PTXParser::tokenToDataType( int token )
	{
		switch( token )
		{
			case TOKEN_U8:   return ir::PTXOperand::u8; break;
			case TOKEN_U16:  return ir::PTXOperand::u16; break;
			case TOKEN_U32:  return ir::PTXOperand::u32; break;
			case TOKEN_U64:  return ir::PTXOperand::u64; break;
			case TOKEN_S8:   return ir::PTXOperand::s8; break;
			case TOKEN_S16:  return ir::PTXOperand::s16; break;
			case TOKEN_S32:  return ir::PTXOperand::s32; break;
			case TOKEN_S64:  return ir::PTXOperand::s64; break;
			case TOKEN_B8:   return ir::PTXOperand::b8; break;
			case TOKEN_B16:  return ir::PTXOperand::b16; break;
			case TOKEN_B32:  return ir::PTXOperand::b32; break;
			case TOKEN_B64:  return ir::PTXOperand::b64; break;
			case TOKEN_PRED: return ir::PTXOperand::pred; break;
			case TOKEN_F16:  return ir::PTXOperand::f16; break;
			case TOKEN_F32:  return ir::PTXOperand::f32; break;
			case TOKEN_F64:  return ir::PTXOperand::f64; break;
			default:
			{
				Exception exception;
				exception.error = State::InvalidDataType;
				
				std::stringstream stream;
				stream << token;
				exception.message = "Got invalid data type " + stream.str();
				report("PTXParser::tokenToDataType(" << token << ") - " << exception.message);
				throw exception;
				break;
			}
		}
		
		return ir::PTXOperand::TypeSpecifier_invalid;
	}

	ir::PTXOperand::Vec PTXParser::tokenToVec( int token )
	{
		switch( token )
		{
			case TOKEN_V2: return ir::PTXOperand::v2; break;
			case TOKEN_V4: return ir::PTXOperand::v4; break;			
			default:
			{
				Exception exception;
				exception.error = State::InvalidVecType;
				
				std::stringstream stream;
				stream << token;
				exception.message = "Got invalid vector type " + stream.str();
				throw exception;
				break;
			}
		}
		
		return ir::PTXOperand::v1;
	}

	ir::PTXOperand::VectorIndex PTXParser::tokenToVectorIndex( int token )
	{
		switch( token )
		{
			case TOKEN_X: return ir::PTXOperand::ix;
			case TOKEN_Y: return ir::PTXOperand::iy;
			case TOKEN_Z: return ir::PTXOperand::iz;
			case TOKEN_W: return ir::PTXOperand::iw;
		}
		return ir::PTXOperand::ix;
	}

	ir::PTXInstruction::Opcode PTXParser::stringToOpcode( std::string string )
	{ // | OPCODE_SULD | OPCODE_TXQ | OPCODE_SUST | OPCODE_SURED | OPCODE_SUQ
		if( string == "abs" ) return ir::PTXInstruction::Abs; 
		if( string == "add" ) return ir::PTXInstruction::Add;
		if( string == "addc" ) return ir::PTXInstruction::AddC;
		if( string == "and" ) return ir::PTXInstruction::And;
		if( string == "atom" ) return ir::PTXInstruction::Atom;
		if( string == "bar.sync" ) return ir::PTXInstruction::Bar;
		if( string == "bar" ) return ir::PTXInstruction::Bar;
		if( string == "bfi" ) return ir::PTXInstruction::Bfi;
		if( string == "bfind" ) return ir::PTXInstruction::Bfind;
		if( string == "bra" ) return ir::PTXInstruction::Bra;
		if( string == "brev" ) return ir::PTXInstruction::Brev;
		if( string == "brkpt" ) return ir::PTXInstruction::Brkpt;
		if( string == "call" ) return ir::PTXInstruction::Call;
		if( string == "clz" ) return ir::PTXInstruction::Clz;
		if( string == "cnot" ) return ir::PTXInstruction::CNot;
		if( string == "copysign" ) return ir::PTXInstruction::CopySign;
		if( string == "cos" ) return ir::PTXInstruction::Cos;
		if( string == "cvt" ) return ir::PTXInstruction::Cvt;
		if( string == "cvta" ) return ir::PTXInstruction::Cvta;
		if( string == "div" ) return ir::PTXInstruction::Div;
		if( string == "ex2" ) return ir::PTXInstruction::Ex2;
		if( string == "exit" ) return ir::PTXInstruction::Exit;
		if( string == "fma" ) return ir::PTXInstruction::Fma;
		if( string == "isspacep" ) return ir::PTXInstruction::Isspacep;
		if( string == "ld" ) return ir::PTXInstruction::Ld;
		if( string == "ldu" ) return ir::PTXInstruction::Ldu;
		if( string == "lg2" ) return ir::PTXInstruction::Lg2;
		if( string == "mad24" ) return ir::PTXInstruction::Mad24;
		if( string == "mad" ) return ir::PTXInstruction::Mad;
		if( string == "max" ) return ir::PTXInstruction::Max;
		if( string == "membar" ) return ir::PTXInstruction::Membar;
		if( string == "min" ) return ir::PTXInstruction::Min;
		if( string == "mov" ) return ir::PTXInstruction::Mov;
		if( string == "mul24" ) return ir::PTXInstruction::Mul24;
		if( string == "mul" ) return ir::PTXInstruction::Mul;
		if( string == "neg" ) return ir::PTXInstruction::Neg;
		if( string == "not" ) return ir::PTXInstruction::Not;
		if( string == "pmevent" ) return ir::PTXInstruction::Pmevent;
		if( string == "popc" ) return ir::PTXInstruction::Popc;
		if( string == "prmt" ) return ir::PTXInstruction::Prmt;
		if( string == "or" ) return ir::PTXInstruction::Or;
		if( string == "rcp" ) return ir::PTXInstruction::Rcp;
		if( string == "red" ) return ir::PTXInstruction::Red;
		if( string == "rem" ) return ir::PTXInstruction::Rem;
		if( string == "ret" ) return ir::PTXInstruction::Ret;
		if( string == "rsqrt" ) return ir::PTXInstruction::Rsqrt;
		if( string == "sad" ) return ir::PTXInstruction::Sad;
		if( string == "selp" ) return ir::PTXInstruction::SelP;
		if( string == "set" ) return ir::PTXInstruction::Set;
		if( string == "setp" ) return ir::PTXInstruction::SetP;
		if( string == "shl" ) return ir::PTXInstruction::Shl;
		if( string == "shr" ) return ir::PTXInstruction::Shr;
		if( string == "sin" ) return ir::PTXInstruction::Sin;
		if( string == "slct" ) return ir::PTXInstruction::SlCt;
		if( string == "sqrt" ) return ir::PTXInstruction::Sqrt;
		if( string == "st" ) return ir::PTXInstruction::St;
		if( string == "sub" ) return ir::PTXInstruction::Sub;
		if( string == "subc" ) return ir::PTXInstruction::SubC;
		if( string == "suld") return ir::PTXInstruction::Suld;
		if( string == "sust") return ir::PTXInstruction::Sust;
		if( string == "sured") return ir::PTXInstruction::Sured;
		if( string == "suq") return ir::PTXInstruction::Suq;
		if( string == "txq") return ir::PTXInstruction::Txq;
		if( string == "testp" ) return ir::PTXInstruction::TestP;
		if( string == "tex" ) return ir::PTXInstruction::Tex;
		if( string == "trap" ) return ir::PTXInstruction::Trap;
		if( string == "vote" ) return ir::PTXInstruction::Vote;
		if( string == "xor" ) return ir::PTXInstruction::Xor;
	
		return ir::PTXInstruction::Nop;
	}

	
	ir::PTXInstruction::Modifier PTXParser::tokenToModifier( int token )
	{
		switch( token )
		{
			case TOKEN_HI: return ir::PTXInstruction::hi; break;
			case TOKEN_LO: return ir::PTXInstruction::lo; break;
			case TOKEN_WIDE: return ir::PTXInstruction::wide; break;
			case TOKEN_SAT: return ir::PTXInstruction::sat; break;
			case TOKEN_RNI: /* fall through */
			case TOKEN_RN: return ir::PTXInstruction::rn; break;
			case TOKEN_RZI: /* fall through */
			case TOKEN_RZ: return ir::PTXInstruction::rz; break;
			case TOKEN_RMI: /* fall through */
			case TOKEN_RM: return ir::PTXInstruction::rm; break;
			case TOKEN_RPI: /* fall through */
			case TOKEN_RP: return ir::PTXInstruction::rp; break;
			case TOKEN_FTZ: return ir::PTXInstruction::ftz; break;
			case TOKEN_APPROX: return ir::PTXInstruction::approx; break;			
			default: break;
		}
		
		return ir::PTXInstruction::Modifier_invalid;
	}
	
	ir::PTXInstruction::AddressSpace PTXParser::tokenToAddressSpace( int token )
	{
		switch( token )
		{
			case TOKEN_CONST: return ir::PTXInstruction::Const; break;
			case TOKEN_GLOBAL: return ir::PTXInstruction::Global; break;
			case TOKEN_LOCAL: return ir::PTXInstruction::Local; break;
			case TOKEN_PARAM: return ir::PTXInstruction::Param; break;
			case TOKEN_SHARED: return ir::PTXInstruction::Shared; break;
			default: break;
		}
		
		return ir::PTXInstruction::AddressSpace_Invalid;
	}

	ir::PTXStatement::Directive PTXParser::tokenToDirective( int token )
	{
		switch( token )
		{
			case TOKEN_CONST: return ir::PTXStatement::Const; break;
			case TOKEN_GLOBAL: return ir::PTXStatement::Global; break;
			case TOKEN_LOCAL: return ir::PTXStatement::Local; break;
			case TOKEN_PARAM: return ir::PTXStatement::Param; break;
			case TOKEN_SHARED: return ir::PTXStatement::Shared; break;
			default: break;
		}
		
		return ir::PTXStatement::Directive_invalid;
	}
					
	ir::PTXInstruction::ReductionOperation 
		PTXParser::tokenToReductionOperation( int token )
	{
		switch( token )
		{
			case TOKEN_AND: return ir::PTXInstruction::ReductionAnd; break;
			case TOKEN_XOR: return ir::PTXInstruction::ReductionXor; break;
			case TOKEN_OR: return ir::PTXInstruction::ReductionOr; break;
			case TOKEN_ADD: return ir::PTXInstruction::ReductionAdd; break;
			case TOKEN_INC: return ir::PTXInstruction::ReductionInc; break;
			case TOKEN_DEC: return ir::PTXInstruction::ReductionDec; break;
			case TOKEN_MIN: return ir::PTXInstruction::ReductionMin; break;
			case TOKEN_MAX: return ir::PTXInstruction::ReductionMax; break;
			case TOKEN_POPC: return ir::PTXInstruction::ReductionPopc; break;
			default: break;
		}
		
		return ir::PTXInstruction::ReductionOperation_Invalid;
	}
	
	ir::PTXInstruction::AtomicOperation 
		PTXParser::tokenToAtomicOperation( int token )
	{
		switch( token )
		{
			case TOKEN_AND: return ir::PTXInstruction::AtomicAnd; break;
			case TOKEN_XOR: return ir::PTXInstruction::AtomicXor; break;
			case TOKEN_OR: return ir::PTXInstruction::AtomicOr; break;
			case TOKEN_ADD: return ir::PTXInstruction::AtomicAdd; break;
			case TOKEN_INC: return ir::PTXInstruction::AtomicInc; break;
			case TOKEN_DEC: return ir::PTXInstruction::AtomicDec; break;
			case TOKEN_MIN: return ir::PTXInstruction::AtomicMin; break;
			case TOKEN_MAX: return ir::PTXInstruction::AtomicMax; break;
			case TOKEN_CAS: return ir::PTXInstruction::AtomicCas; break;
			case TOKEN_EXCH: return ir::PTXInstruction::AtomicExch; break;
			default: break;
		}
		
		return ir::PTXInstruction::AtomicOperation_Invalid;		
	}
	
	ir::PTXInstruction::CmpOp PTXParser::tokenToCmpOp( int token )
	{
		switch( token )
		{
			case TOKEN_EQ: return ir::PTXInstruction::Eq; break;
			case TOKEN_NE: return ir::PTXInstruction::Ne; break;
			case TOKEN_LT: return ir::PTXInstruction::Lt; break;
			case TOKEN_LE: return ir::PTXInstruction::Le; break;
			case TOKEN_GT: return ir::PTXInstruction::Gt; break;
			case TOKEN_GE: return ir::PTXInstruction::Ge; break;
			case TOKEN_LO: return ir::PTXInstruction::Lo; break;
			case TOKEN_LS: return ir::PTXInstruction::Ls; break;
			case TOKEN_HI: return ir::PTXInstruction::Hi; break;
			case TOKEN_HS: return ir::PTXInstruction::Hs; break;
			case TOKEN_EQU: return ir::PTXInstruction::Equ; break;
			case TOKEN_NEU: return ir::PTXInstruction::Neu; break;
			case TOKEN_LTU: return ir::PTXInstruction::Ltu; break;
			case TOKEN_LEU: return ir::PTXInstruction::Leu; break;
			case TOKEN_GTU: return ir::PTXInstruction::Gtu; break;
			case TOKEN_GEU: return ir::PTXInstruction::Geu; break;
			case TOKEN_NUM: return ir::PTXInstruction::Num; break;
			case TOKEN_NAN: return ir::PTXInstruction::Nan; break;
			default: break;
		}
		
		return ir::PTXInstruction::CmpOp_Invalid;	
	}
	
	ir::PTXInstruction::CacheOperation PTXParser::tokenToCacheOperation(int token)
	{
		switch (token)
		{
			case TOKEN_CA: return ir::PTXInstruction::Ca;
			case TOKEN_WB: return ir::PTXInstruction::Wb;
			case TOKEN_CG: return ir::PTXInstruction::Cg;
			case TOKEN_CS: return ir::PTXInstruction::Cs;
			case TOKEN_CV: return ir::PTXInstruction::Cv;
			case TOKEN_WT: return ir::PTXInstruction::Wt;
			default: break;
		}
		return ir::PTXInstruction::CacheOperation_Invalid;
	}
	
	ir::PTXInstruction::ClampOperation PTXParser::tokenToClampOperation(int token) {
		switch (token)
		{
			case TOKEN_TRAP: return ir::PTXInstruction::TrapOOB;
			case TOKEN_CLAMP: return ir::PTXInstruction::Clamp;
			case TOKEN_ZERO: return ir::PTXInstruction::Zero;
			default: break;
		}
		return ir::PTXInstruction::ClampOperation_Invalid;
	}
	
	ir::PTXInstruction::FormatMode PTXParser::tokenToFormatMode(int token)
	{
		switch (token)
		{
			case TOKEN_Z: return ir::PTXInstruction::Unformatted;
			case TOKEN_B: return ir::PTXInstruction::Unformatted;
			case TOKEN_P: return ir::PTXInstruction::Formatted;
			default: break;
		}
		return ir::PTXInstruction::FormatMode_Invalid;
	}
	
	ir::PTXInstruction::SurfaceQuery PTXParser::tokenToSurfaceQuery(int token)
	{
		report("tokenToSurfaceQuery(" << token << ")");
		
		switch (token)
		{
			case TOKEN_WIDTH: return ir::PTXInstruction::Width;
			case TOKEN_HEIGHT: return ir::PTXInstruction::Height;
			case TOKEN_DEPTH: return ir::PTXInstruction::Depth;
			case TOKEN_CHANNEL_DATA_TYPE: return ir::PTXInstruction::ChannelDataType;
			case TOKEN_CHANNEL_ORDER: return ir::PTXInstruction::ChannelOrder;
			case TOKEN_NORMALIZED_COORDS: return ir::PTXInstruction::NormalizedCoordinates;
			case TOKEN_FILTER_MODE: return ir::PTXInstruction::SamplerFilterMode;
			case TOKEN_ADDR_MODE_0: return ir::PTXInstruction::SamplerAddrMode0;
			case TOKEN_ADDR_MODE_1: return ir::PTXInstruction::SamplerAddrMode1;
			case TOKEN_ADDR_MODE_2: return ir::PTXInstruction::SamplerAddrMode2;
			default: break;
		}
		return ir::PTXInstruction::SurfaceQuery_Invalid;
	}
	
	ir::PTXInstruction::BarrierOperation PTXParser::tokenToBarrierOp(int token)
	{
		switch( token )
		{
			case TOKEN_ARRIVE: return ir::PTXInstruction::BarArrive;
			case TOKEN_RED: return ir::PTXInstruction::BarReduction;
			default:
				break;
		}
		return ir::PTXInstruction::BarSync;
	}
	
	ir::PTXInstruction::BoolOp PTXParser::tokenToBoolOp( int token )
	{
		switch( token )
		{
			case TOKEN_AND: return ir::PTXInstruction::BoolAnd; break;
			case TOKEN_OR: return ir::PTXInstruction::BoolOr; break;
			case TOKEN_XOR: return ir::PTXInstruction::BoolXor; break;
			default: break;
		
		}
		
		return ir::PTXInstruction::BoolOp_Invalid;
	}

	ir::PTXInstruction::Geometry PTXParser::tokenToGeometry( int token )
	{
		switch( token )
		{
			case TOKEN_1D: return ir::PTXInstruction::_1d; break;
			case TOKEN_2D: return ir::PTXInstruction::_2d; break;
			case TOKEN_3D: return ir::PTXInstruction::_3d; break;
			default: break;
		}
		
		return ir::PTXInstruction::Geometry_Invalid;		
	}
	
	ir::PTXInstruction::VoteMode PTXParser::tokenToVoteMode( int token )
	{
		switch( token )
		{
			case TOKEN_ANY: return ir::PTXInstruction::Any; break;
			case TOKEN_ALL: return ir::PTXInstruction::All; break;
			case TOKEN_UNI: return ir::PTXInstruction::Uni; break;
			default: break;
		}
		
		return ir::PTXInstruction::VoteMode_Invalid;		
	}
	
	ir::PTXInstruction::Level PTXParser::tokenToLevel( int token )
	{
		switch( token )
		{
			case TOKEN_CTA: return ir::PTXInstruction::CtaLevel; break;
			case TOKEN_GL: return ir::PTXInstruction::GlobalLevel; break;
			default: break;
		}
		
		return ir::PTXInstruction::Level_Invalid;		
	}
	
	ir::PTXInstruction::PermuteMode PTXParser::tokenToPermuteMode( int token )
	{
		switch( token )
		{
			case TOKEN_F4E: return ir::PTXInstruction::ForwardFourExtract; 
				break;
			case TOKEN_B4E: return ir::PTXInstruction::BackwardFourExtract; 
				break;
			case TOKEN_RC8: return ir::PTXInstruction::ReplicateEight;    break;
			case TOKEN_ECL: return ir::PTXInstruction::EdgeClampLeft;     break;
			case TOKEN_ECR: return ir::PTXInstruction::EdgeClampRight;    break;
			case TOKEN_RC16: return ir::PTXInstruction::ReplicateSixteen; break;
				break;
			default: break;
		}
		
		return ir::PTXInstruction::DefaultPermute;
	}

	ir::PTXInstruction::FloatingPointMode PTXParser::tokenToFloatingPointMode( 
		int token )
	{
		switch( token )
		{
			case TOKEN_FINITE:    return ir::PTXInstruction::Finite;    break;
			case TOKEN_INFINITE:  return ir::PTXInstruction::Infinite;  break;
			case TOKEN_NUMBER:    return ir::PTXInstruction::Number;    break;
			case TOKEN_NOT_A_NUMBER: 
				return ir::PTXInstruction::NotANumber; break;
			case TOKEN_NORMAL:    return ir::PTXInstruction::Normal;    break;
			case TOKEN_SUBNORMAL: return ir::PTXInstruction::SubNormal; break;
			default: break;
		}
		
		return ir::PTXInstruction::FloatingPointMode_Invalid;
	}

	ir::PTXStatement::TextureSpace PTXParser::tokenToTextureSpace( int token )
	{
		switch( token )
		{
			case TOKEN_GLOBAL: return ir::PTXStatement::GlobalSpace;    break;
			case TOKEN_PARAM:  return ir::PTXStatement::ParameterSpace; break;
		}
		return ir::PTXStatement::InvalidSpace;
	}
	
	ir::PTXOperand::DataType PTXParser::smallestType( long long int value )
	{
		return ir::PTXOperand::s64;
	}
	
	ir::PTXOperand::DataType 
		PTXParser::smallestType( long long unsigned int value )
	{
		return ir::PTXOperand::u64;
	}

	PTXParser::PTXParser()
	{

	}
				
	void PTXParser::parse( std::istream& input, 
		ir::Instruction::Architecture language )
	{
		assert( language == ir::Instruction::PTX );
	
		std::stringstream temp;
		
		report( "Parsing file " << fileName );
		report( "Running 2.1 main parse pass." );
		
		parser::PTXLexer lexer( &input, &temp );
		reset();
		
		
		try 
		{
			state.addSpecialRegisters();
			ptx::yyparse( lexer, state );
			assert( temp.str().empty() );
		
			checkLabels();
		}
		catch( Exception& e )
		{
			input.seekg( 0, std::ios::end );
			unsigned int length = input.tellg();
			input.seekg( 0, std::ios::beg );
			
			char* temp = new char[ length + 1 ];
			temp[ length ] = '\0';
			input.read( temp, length );
			e.message = "\nFailed to parse file '" + fileName + "':\n" 
				+ hydrazine::addLineNumbers(temp) + "\n" + e.message;
			delete[] temp;
			
			report("parse error");
			report(e.what());
			throw e;
		}
	}
	
	ir::Module::StatementVector&& PTXParser::statements()
	{
		return std::move( state.statements );
	}
		
}

#endif

