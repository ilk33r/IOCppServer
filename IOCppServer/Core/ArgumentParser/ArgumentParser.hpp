//
//  ArgumentParser.hpp
//  Toqmak
//
//  Created by İlker ÖZCAN on 02/12/2017.
//  Copyright © 2017 ilker özcan. All rights reserved.
//

#ifndef ArgumentParser_hpp
#define ArgumentParser_hpp

#include <map>
#include <string>

namespace IO {
	namespace Core {
		
		using namespace std;
		
		class ArgumentParser {
			
#pragma mark Properties
		private:
			typedef struct Argument {
				string argName;
				string argShortName;
				string description;
				string strValue;
				int intValue;
				bool booleanValue;
				bool hidden;
			} Argument;
			map<string, Argument> _values;
			
		public:
			string appPath;
			
#pragma mark Publics
		public:
			ArgumentParser();
			bool getBoolean(const string &argumentName);
			int getInt(const string &argumentName);
			string *getString(const string &argumentName);
			void parseArguments(int argc, const char *argv[]);
			void registerArgument(const string &argName, const string &argShortName, const string &description, bool hidden);
			
#pragma mark Privates
		private:
			Argument *getValue(const string &argumentName);
		};
	}
}

#endif /* ArgumentParser_hpp */
