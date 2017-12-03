//
//  String+Format.cpp
//  Toqmak
//
//  Created by İlker ÖZCAN on 02/12/2017.
//  Copyright © 2017 ilker özcan. All rights reserved.
//

#include "StringUtils.hpp"

using namespace IO::Common;

#pragma mark Publics

template<typename ... Args>
string StringUtils::format(const string &format, Args ... args) {
	// Obtain string size
	size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1;
	
	// Create buffer
	unique_ptr<char[]> buf(new char[size]);
	
	// Format string
	snprintf(buf.get(), size, format.c_str(), args ...);
	
	// Create and return new string
	return string(buf.get(), buf.get() + size - 1);
}
