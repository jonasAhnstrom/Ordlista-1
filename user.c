#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>

#include "user.h"
#include "strlib.h"
#include "strmanip.h"
#include "genlib.h"
#include "messer.h"

void userNewUser(User *pUserInput){
	Vector input;
	vectorInit(&input);
	pUserInput->input = input;
	pUserInput->globals.filename = "";
	pUserInput->globals.modified = FALSE;
}
void userSetCom(Command com, User *pUserInput){
	pUserInput->command = com;
}
Command userGetCom(User *pUserInput){
	return pUserInput->command;
}
Vector* userGetVector(User *pUserInput){
	return &pUserInput->input;
}
void userAddInput(void* input, int sizeOfElem, User *pUserInput){
	if (inType == digit){
		vectorAppend(&pUserInput->input, &input, sizeOfElem);
	}
	else{
		vectorAppend(&pUserInput->input, input, sizeOfElem);
	}
}
void* userGetInput(User *pUserInput, int index){
	if (inType == digit){
		return (int*)vectorGet(&pUserInput->input, index);
	}
	else{
		return (String)vectorGet(&pUserInput->input, index);
	}
}
void userSetFilename(String filename, User *pUserInput){
	String str;
	str = CopyString(filename);
	if (!stringIsEmpty(pUserInput->globals.filename)){
		FreeBlock(pUserInput->globals.filename);
	}
	pUserInput->globals.filename = str;
}
String userGetFilename(User *pUserInput){
	return pUserInput->globals.filename;
}
void userSetMod(int n, User *pUserInput){
	pUserInput->globals.modified = n;
}
Bool userGetMod(User *pUserInput){
	return pUserInput->globals.modified;
}
void userSetEnv(int n, jmp_buf *env){
	error = n;
	errorSetEnv(env);
}
int userGetNoError(){
	return (error == 0);
}
void userSetInType(InputType t){
	inType = t;
}
Bool userGetInType(){
	return inType;
}