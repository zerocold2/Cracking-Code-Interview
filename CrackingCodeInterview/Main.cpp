
#include "ArrayAndStrings.cpp"
#include "LinkedLists.cpp"
#include "Sort.cpp"


using namespace std;
int mat[101][101];
int n;


int main()
{

#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif

	char str[] = "Ahmed nasr ata alazbakawy";
	int arr[10] = { 50,14,3,13,6,7,8,1,12,0 };

	
	ArrayAndStrings::ReplaceSpaces(str);

	LinkedLists* list = new LinkedLists(10);
	int data;
	while (cin >> data && data != 0) {
		list->Add(data);
	}
	list->Print();
	list->Sort();
	cout << endl;
	list->Print();

	/*int m;
	cin >> n >> m;
	for (int i = 0;i < m;++i) {
		for (int j = 0;j < n;++j)
			cin >> mat[i][j];
	}*/
	//erbottlewaterbottlewat
	//cout << ArrayAndStrings::IsSubString("waterbottle", "erbottlewat") << endl;
	/*Sort sort;
	sort.MergeSort(arr, 9);
	int i = 0;
	REP(i, 10)cout << arr[i] << " ";
	cout << endl;
*/


	system("PAUSE");
	return 0;
}

