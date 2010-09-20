/*! \file PTXParser.h
	\date Monday January 19, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the PTXParser class.
*/

#ifndef PTX_PARSER_H_INCLUDED
#define PTX_PARSER_H_INCLUDED

#include <ocelot/parser/interface/Parser.h>

#undef yyFlexLexer
#define yyFlexLexer ptxFlexLexer
#include <FlexLexer.h>

#include <ocelot/parser/interface/PTXLexer.h>
#include <ocelot/ir/interface/Module.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace parser
{
	/*! \brief An implementation of the Parser interface for PTX */
	class PTXParser : public Parser
	{
		public:
			class State
			{
				public:
					class OperandWrapper
					{
						public:
							OperandWrapper( const ir::PTXOperand& o, 
								ir::PTXInstruction::AddressSpace s 
								= ir::PTXInstruction::AddressSpace_Invalid );
						public:
							ir::PTXOperand operand;
							ir::PTXInstruction::AddressSpace space;
					};
					
					class FunctionPrototype
					{
						public:
							typedef std::vector< ir::PTXOperand::DataType > 
								TypeVector;
					
						public:
							TypeVector returnTypes;
							TypeVector argumentTypes;
							std::string name;
					
						public:
							void clear();
							bool compare( const FunctionPrototype& t );
							std::string toString() const;
					};
				
					typedef std::unordered_map< std::string, unsigned int > 
						StringMap;
					typedef std::vector< std::string > StringList;
					typedef std::vector< unsigned int > UintStack;
					typedef std::vector< unsigned int > DimensionVector;
					typedef std::vector< double > DoubleVector;
					typedef std::unordered_map< std::string, 
						OperandWrapper > OperandMap;
					typedef std::unordered_set< std::string > StringSet;
					typedef std::vector< ir::PTXOperand > OperandVector;
					typedef std::unordered_map< std::string, 
						FunctionPrototype > PrototypeMap;
			
					enum Error
					{
						Success,
						SyntaxError,
						MalformedVersion,
						InvalidDataType,
						InvalidVecType,
						InitializerSizeMismatch,
						InvalidInstruction,
						DuplicateDeclaration,
						NoDeclaration,
						InvalidOpcode,
						DuplicateLabel,
						NoPrototype,
						PrototypeMismatch,
						NoLabel,
						InvalidArray,
						NotPredicate,
						NotSupported,
						NotVersion2_1,
						Invalid
					};
			
				public:
					ir::Module::StatementVector statements;
					StringMap labels;
					std::string fileName;
				
				public:
					std::string sectionType;
					std::string sectionName;
					
					StringList identifiers;
					OperandMap operands;
					StringList localOperands;

					PrototypeMap prototypes;
					StringList localPrototypes;
					
					bool inEntry;
					bool inArgumentList;
					bool inReturnList;
					
					unsigned int returnOperands;
					unsigned int alignment;
					ir::PTXOperand operand;
					OperandVector operandVector;
					ir::PTXStatement statement;
					FunctionPrototype prototype;
					
					ir::PTXStatement::Directive directive;
									
				private:
					static ir::PTXInstruction::AddressSpace _toAddressSpace( 
						ir::PTXStatement::Directive directive );
				
				private:
					void _setImmediateTypes();
				
				public:
					void addSpecialRegisters();
				
					void maxnreg( unsigned int regs );
					void maxntid( unsigned int tidx, unsigned int tidy = 1024, 
						unsigned int tidz = 1024 );
					void ctapersm( int target, unsigned int ctas );
					void maxnctapersm( unsigned int ctas );
					void maxnctapersm();
				
				public:
					void preprocessor( int token );
					void version( double version, YYLTYPE& location );
					void identifierList( const std::string& identifier );
					void identifierList2( const std::string& identifier );
					void decimalListSingle( long long int value );
					void decimalListSingle2( long long int value );
					void floatList( double value );
					void floatList1( double value );
					void singleList( float value );
					void singleList1( float value );
					void targetElement( int token );
					void target();
					void noAddressSpace();
					void addressSpace( int token );
					void dataType( int token );
					void statementVectorType( int token );
					void instructionVectorType( int token );
					void attribute( bool visible, bool external );
					void shiftAmount( bool shift );
					void vectorIndex( int token );
					
					void arrayDimensionSet( long long int value, 
						YYLTYPE& location, bool add );
					void arrayDimensionSet();
					void arrayDimensions();
					void assignment();
					void registerDeclaration( const std::string& name, 
						YYLTYPE& location, unsigned int regs = 0 );
					void registerSeperator( YYLTYPE& location );
					void fileDeclaration( unsigned int id, 
						const std::string& name );
					void initializableDeclaration( const std::string& name, 
						YYLTYPE& one, YYLTYPE& two );
					void textureDeclaration( int token, const std::string& name, 
						YYLTYPE& location );
					void parameterDeclaration( const std::string& name, 
						YYLTYPE& location );
					
					void openBrace( YYLTYPE& location );
					void closeBrace( YYLTYPE& location );
					void returnParameterListBegin( YYLTYPE& location );
					void returnParameterListEnd( YYLTYPE& location );
					void parameterListBegin( YYLTYPE& location );
					void parameterListEnd( YYLTYPE& location );
					
					void functionBegin( YYLTYPE& location );
					void functionName( const std::string& name, 
						YYLTYPE& location );
					void functionDeclaration( YYLTYPE& location, bool body );
					
					void entry( const std::string& name, YYLTYPE& location );
					void entryDeclaration( YYLTYPE& location );
					void entryStatement( YYLTYPE& location );
					
					void locationAddress( int token );
					void uninitializableDeclaration( const std::string& name );
					void location( long long int one, long long int two, 
						long long int three );
					void label( const std::string& string );
					void pragma( const std::string& string );
					void labelOperand( const std::string& string );
					void nonLabelOperand( const std::string& string, 
						YYLTYPE& location, bool invert );
					void constantOperand( long long int value );
					void constantOperand( unsigned long long int value );
					void constantOperand( float value );
					void constantOperand( double value );
					void addressableOperand( const std::string& name, 
						long long int value, YYLTYPE& location, 
						bool invert );
					void arrayOperand( YYLTYPE& location );
					void returnOperand();
					void guard( const std::string& name, YYLTYPE& one, 
						bool invert );
					void guard();
					void statementEnd( YYLTYPE& location );
					
					void uni( bool condition );
					void carry( bool condition );
					void modifier( int token );
					void atomic( int token );
					void volatileFlag( bool condition );
					void reduction( int token );
					void comparison( int token );
					void boolean( int token );
					void geometry( int token );
					void vote( int token );
					void level( int token );
					void permute( int token );
					void floatingPointMode( int token );
					void defaultPermute();
					void full();
					
					void instruction();
					void instruction( const std::string& opcode, int dataType, 
						unsigned int operands );
					void instruction( const std::string& opcode, 
						unsigned int operands );
					void tex( int dataType );
					void callPrototypeName( const std::string& identifier );
					void call( const std::string& identifier,
						YYLTYPE& location );
					void carryIn();
					void convert( int token, YYLTYPE& location );
					void convertC( int token, YYLTYPE& location );
					void convertD( int token, YYLTYPE& location );
					
					void returnType( int token );
					void argumentType( int token );
					void callPrototype( const std::string& name, 
						YYLTYPE& location );
					void callTargets( const std::string& name, 
						YYLTYPE& location );
			};
			
			class Exception : public std::exception
			{
				public:
					std::string message;
					State::Error error;
					
				public:
					const char* what() const throw();
					~Exception() throw();
			};
		
		private:
			State state;
		
		private:
			void checkLabels();
			void reset();
		
		public:
			static std::string toString( YYLTYPE&, State& );
			static ir::PTXOperand::DataType tokenToDataType( int );
			static ir::PTXOperand::VectorIndex tokenToVectorIndex( int );
			static ir::PTXInstruction::Vec tokenToVec( int );
			static ir::PTXInstruction::Opcode stringToOpcode( std::string );
			static ir::PTXOperand::SpecialRegister 
				stringToSpecial( std::string );
			static ir::PTXInstruction::Modifier tokenToModifier( int );
			static ir::PTXInstruction::AddressSpace tokenToAddressSpace( int );
			static ir::PTXStatement::Directive tokenToDirective( int );
			static ir::PTXInstruction::ReductionOperation 
				tokenToReductionOperation( int );
			static ir::PTXInstruction::AtomicOperation 
				tokenToAtomicOperation( int );
			static ir::PTXInstruction::CmpOp tokenToCmpOp( int );
			static ir::PTXInstruction::BoolOp tokenToBoolOp( int );
			static ir::PTXInstruction::Geometry tokenToGeometry( int );
			static ir::PTXInstruction::VoteMode tokenToVoteMode( int );
			static ir::PTXInstruction::Level tokenToLevel( int );
			static ir::PTXInstruction::PermuteMode tokenToPermuteMode( int );
			static ir::PTXInstruction::FloatingPointMode
				tokenToFloatingPointMode( int);
			static ir::PTXStatement::TextureSpace tokenToTextureSpace( int );
			static ir::PTXOperand::DataType smallestType( long long int );
			static ir::PTXOperand::DataType 
				smallestType( long long unsigned int );
			
		public:
			PTXParser();
			void parse( std::istream& input, 
				ir::Instruction::Architecture language = ir::Instruction::PTX );
			ir::Module::StatementVector&& statements();	
	};

}

#endif
