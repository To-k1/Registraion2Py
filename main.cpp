#include <iostream>
#include "Registrating.h"
#include <string>
using namespace std;

int main() {
	string srcPattern = "F:\\shixi\\CS\\registration\\registration\\srcImg";
	string binPattern = "F:\\shixi\\CS\\registration\\registration\\binImg";
	string dstPattern = "F:\\shixi\\CS\\registration\\registration\\dstImg";
	char useSemiAuto = 'n';
	char useFailedImg = 'n';
	int startPos = 0;
	Registrator registrator;
	registrator.registrating(srcPattern, binPattern, dstPattern, useSemiAuto, useFailedImg, startPos);

	return 0;
}