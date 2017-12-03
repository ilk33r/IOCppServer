//
//  ArgumentParser.cpp
//  Toqmak
//
//  Created by İlker ÖZCAN on 02/12/2017.
//  Copyright © 2017 ilker özcan. All rights reserved.
//

#include "ArgumentParser.hpp"

using namespace IO::Core;

#pragma mark Properties

struct Argument {
	string argName;
	string argShortName;
	string description;
	string strValue;
	int intValue;
	bool booleanValue;
	bool hidden;
};

#pragma mark Initialization Methods

ArgumentParser::ArgumentParser() {
	// Register default arguments
	this->registerArgument("configdump", "cd", "Display all configuration", false);
	this->registerArgument("debug", "d", "Debug mode", false);
	this->registerArgument("help", "h", "Display help", false);
	this->registerArgument("version", "v", "Display version", false);
	this->registerArgument("buildinfo", "bi", "Display build info", false);
}

#pragma mark Publics

bool ArgumentParser::getBoolean(const string &argumentName) {
	// Get value from values
	Argument *argValue = this->getValue(argumentName);
	
	// Check value is not exists
	if (argValue == NULL) {
		return false;
	}
	
	return argValue->booleanValue;
}

int ArgumentParser::getInt(const string &argumentName) {
	// Get value from values
	Argument *argValue = this->getValue(argumentName);
	
	// Check value is not exists
	if (argValue == NULL) {
		return false;
	}
	
	return argValue->intValue;
}

string *ArgumentParser::getString(const string &argumentName) {
	// Get value from values
	Argument *argValue = this->getValue(argumentName);
	
	// Check value is not exists
	if (argValue == NULL) {
		return NULL;
	}
	
	return &argValue->strValue;
}

void ArgumentParser::parseArguments(int argc, const char *argv[]) {
	// Update app path properties
	this->appPath = argv[0];
	
	// Loop throught arguments
	for (int i = 1; i < argc; i++) {
		// Obtain argument from index
		string argument = argv[i];
		
		// Check argument is defined
	}
}

void ArgumentParser::registerArgument(const string &argName, const string &argShortName, const string &description, bool hidden) {
	// Check argument is not exists
	if (this->getValue(argName) != NULL) {
		// Create key value argument
		Argument valueArgument = Argument();
		valueArgument.argName = argName;
		valueArgument.argShortName = argShortName;
		valueArgument.description = description;
		valueArgument.hidden = hidden;
		
		// Add argument to values
		_values.insert(make_pair(argName, valueArgument));
	}
}

#pragma mark Privates

ArgumentParser::Argument *ArgumentParser::getValue(const string &argumentName) {
	// Find element from values
	map<string, Argument>::iterator iterator = _values.find(argumentName);

	// Check value exists
	if(iterator == _values.end()) {
		return NULL;
	}
	
	return &iterator->second;
}

