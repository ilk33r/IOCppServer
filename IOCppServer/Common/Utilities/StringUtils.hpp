//
//  String+Format.hpp
//  IOCppServer
//
//  Created by İlker ÖZCAN on 02/12/2017.
//  Copyright © 2017 ilker özcan. All rights reserved.
//

#ifndef String_Format_hpp
#define String_Format_hpp

#include <memory>
#include <string>


namespace IO {
	namespace Common {
		
		using namespace std;
		
		class StringUtils {
			
#pragma mark Publics
		public:
			template<typename ... Args>
			static string format(const string &format, Args ... args);
		};
	}
}

#endif /* String_Format_hpp */
