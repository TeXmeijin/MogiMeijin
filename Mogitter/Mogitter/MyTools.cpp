#include "stdafx.h"
#include "ShareData.h"
#include "MyTools.h"

using namespace Mogitter;

MyTools::MyTools(void)
{
}

bool MyTools::isExistTheFile(String^ path){
	FileInfo^ f = gcnew FileInfo(path);
	return f->Exists;
}

void MyTools::writeTextFile(String^ txt,String^ path,String^ encode){
	StreamWriter^ writer = gcnew StreamWriter(path,false,System::Text::Encoding::GetEncoding(encode));
	writer->Write(txt);
	writer->Close();
}

void MyTools::writeTextFile(String^ txt,String^ path){
	writeTextFile(txt,path,ShareData::defaultEncode);
}

String^ MyTools::getTextFile(String^ path,String^ encode){

	if (!isExistTheFile(path))
	{
		return "";
	}

	String^ ret;
	StreamReader^ reader = gcnew StreamReader(path,System::Text::Encoding::GetEncoding(encode));
	ret = reader->ReadToEnd();
	reader->Close(); 
	return ret;
}

String^ MyTools::getTextFile(String^ path){
	return getTextFile(path,ShareData::defaultEncode);
}

String^ MyTools::getParent(String^ path){

	if (!isExistTheFile(path))
	{
		return "";
	}

	FileInfo^ fi=gcnew FileInfo(path);
	return fi->DirectoryName;
}

String^ MyTools::getApplicationDirectory(){
	return getParent(Application::ExecutablePath);
}

bool MyTools::isOKString(String^ txt){
	int kakkoCount=0;

	txt=txt->Replace("\"{\"","#####");
	txt=txt->Replace("\"}\"","#####");

	array<wchar_t>^ ary=txt->ToCharArray();
	for(int i=0;i<ary->Length;i++)
	{
		if (ary[i]=='{')
		{
			kakkoCount++;
		}
		else if (ary[i]=='}')
		{
			kakkoCount--;
		}
		if (kakkoCount<0)
		{
			return false;
		}
	}
	return kakkoCount==0;
}
