//
//  ArgumentParserException.cpp
//  Toqmak
//
//  Created by İlker ÖZCAN on 02/12/2017.
//  Copyright © 2017 ilker özcan. All rights reserved.
//

#include "ArgumentParserException.hpp"

using namespace IO::Core;

#pragma mark Initialization Methods

ArgumentParserException::ArgumentParserException(int argumentIndex, string &argumentName)
: invalid_argument("Invalid argument"), argumentIndex(argumentIndex), argumentName(argumentName) {
}

const char *ArgumentParserException::what() const throw() {
	// Create exception string format
	const char *whatString = "Invalid argument %s index of %d";
	
}

const char *what() const throw() {
	
	cnvt << runtime_error::what() << ": " << getNumerator()
	<< " / " << getDenominator();
	
	return cnvt.str().c_str();
	}
	
	int getNumerator() const
	{ return numerator; }
	
	int getDenominator() const
	{ return denominator; }
	
	template<typename T>
	static T divide(const T& n1, const T& n2)
	{
		if ( n2 == T( 0 ) ) {
			throw DivideByZeroException( n1, n2 );
		}
		
		return ( n1 / n2 );
	}
}
