#pragma once

namespace Mogitter
{
	ref class MyTools
	{
	public:
		MyTools(void);
		static bool isOKString(String^ txt);
		static String^ getApplicationDirectory();
		static String^ getParent(String^ path);
		static String^ getTextFile(String^ path);
		static String^ getTextFile(String^ path,String^ encode);
		static bool isExistTheFile(String^ path);
		static void writeTextFile(String^ txt,String^ path);
		static void writeTextFile(String^ txt,String^ path,String^ encode);
	}; 
}

