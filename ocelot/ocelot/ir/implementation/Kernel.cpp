/*! \file Kernel.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 15 Jan 2009 ; 21 Jan 2009
	\brief implements the Kernel base class
*/

#include <ocelot/ir/interface/Kernel.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

ir::Kernel::Kernel(Instruction::Architecture isa, const std::string& n, 
	bool isFunction, const ir::Module* m) :
	_function(isFunction), name(n), ISA(isa), module(m) {
}

ir::Kernel::~Kernel() {
}

ir::Kernel::Kernel(const Kernel &kernel) {
	// deep copy the elements from a kernel to this one

	name       = kernel.name;
	ISA        = kernel.ISA;
	parameters = kernel.parameters;
	arguments  = kernel.arguments;
	locals     = kernel.locals;
	_function  = kernel.function();

	module = kernel.module;
}

const ir::Kernel& ir::Kernel::operator=(const Kernel &kernel) {
	// deep copy the elements from a kernel to this one
	if( &kernel == this ) return *this;

	name = kernel.name;
	ISA = kernel.ISA;
	parameters = kernel.parameters;
	arguments = kernel.arguments;
	locals = kernel.locals;
	_function = kernel.function();

	module = kernel.module;

	return *this;	
}

ir::Parameter* ir::Kernel::getParameter(const std::string& name) {
	using namespace std;

	
	ParameterMap::iterator p_it = parameters.find(name);
	if (p_it != parameters.end()) {
		report("getParameter(" << name << ") returned in Kernel::parameters");
		return &p_it->second;
	}

	for (ParameterVector::iterator p_it = arguments.begin(); 
		p_it != arguments.end(); ++p_it) {
		if (p_it->name == name) {
		report("getParameter(" << name << ") returned in Kernel::arguments");
			return &*p_it;
		}
	}
	
	return 0;
}

const ir::Parameter* ir::Kernel::getParameter(const std::string& name) const {
	using namespace std;

	ParameterMap::const_iterator p_it = parameters.find(name);
	if (p_it != parameters.end()) {
		return &p_it->second;
	}

	for (ParameterVector::const_iterator p_it = arguments.begin(); 
		p_it != arguments.end(); ++p_it) {
		if (p_it->name == name) {
			return &*p_it;
		}
	}

	return 0;
}

void ir::Kernel::insertParameter(const ir::Parameter &parameter, bool asParameter) {
	if (asParameter) {
		parameters[parameter.name] = parameter;
	}
	else {
		arguments.push_back(parameter);
	}
}

bool ir::Kernel::function() const {
	return _function;
}

void ir::Kernel::write(std::ostream& stream) const {
	assertM(false, "Writing to a stream not possible from base Kernel class.");
}

std::ostream& operator<<(std::ostream& s, const ir::Kernel& k) {
	k.write(s);
	return s;
}

