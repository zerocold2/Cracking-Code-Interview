
#include "PeakFinding.cpp"
#include "ArrayAndStrings.cpp"
#include "LinkedLists.cpp"

using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	char str[] = "Ahmed nasr ata alazbakawy";
	int arr[10] = { 5,4,3,13,6,7,8,11,12,20 };

	//cout << PeakFinding::FindPeak(arr, sizeof(arr) / sizeof(int)) << endl;
	//ArrayAndStrings::ReplaceSpaces(str);
	
	LinkedLists* list = new LinkedLists(2);
	int data;
	while (cin >> data && data != 0) {
		list->Add(data);
	}
	list->Print();
	system("PAUSE");
	return 0;
}

