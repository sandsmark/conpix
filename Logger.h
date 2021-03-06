/*
 * Logger.h
 *
 *  Created on: 04.12.2010
 *      Author: rofl
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include<string>
#include<fstream>

#include "Interfaces.h"

/*
class ILogger {
public:
	ILogger() {};
	virtual ~ILogger() {};
	virtual void log(string s);
	virtual void logln(string s);

};
*/
DeclareInterface(ILogger)
	virtual void log(std::string s);
	virtual void logln(std::string s);
EndInterface

class SimpleConsoleLogger : implements ILogger {
	virtual void log(std::string s);
	virtual void logln(std::string s);
};

class SimpleFileLogger : implements ILogger {
private:
	std::string outfile;
	std::ofstream myfile;
public:
	SimpleFileLogger(std::string out_file);

	virtual ~SimpleFileLogger();
	virtual void log(std::string s);
	virtual void logln(std::string s);

/*	virtual void logln(string s) {
		log(s);
		log("\n");
	}

	virtual void log(string s) {
		myfile << s;
	}
*/
/*
	virtual void log(void* buf, size_t bufsize){
		string mybuf;
		mybuf.length = bufsize;
		memcpy(mybuf.ptr, buf, bufsize);
		myfile.write(mybuf);
	}
*/
	virtual void clear();
};

#endif /* LOGGER_H_ */
