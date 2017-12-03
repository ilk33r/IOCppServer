//
//  ArgumentParserException.hpp
//  Toqmak
//
//  Created by İlker ÖZCAN on 02/12/2017.
//  Copyright © 2017 ilker özcan. All rights reserved.
//

#ifndef ArgumentParserException_hpp
#define ArgumentParserException_hpp

#include <exception>
#include <stdexcept>
#include <string>

namespace IO {
	namespace Core {
		
		using namespace std;
		
		class ArgumentParserException: public runtime_error {

#pragma mark Properties
		private:
			int argumentIndex;
			string argumentName;
			
#pragma mark Publics
			
		public:
			ArgumentParserException();
		};
	}
}

#endif /* ArgumentParserException_hpp */
