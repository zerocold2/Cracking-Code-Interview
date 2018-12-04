
#include "PeakFinding.cpp"
#include "ArrayAndStrings.cpp"
#include "LinkedLists.cpp"

using namespace std;
char mat[101][101];
int n;
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

	/*LinkedLists* list = new LinkedLists(2);
	int data;
	while (cin >> data && data != 0) {
		list->Add(data);
	}
	list->Print();*/
	cin >> n;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j)
			cin >> mat[i][j];
	}
	ArrayAndStrings::RotateImageBy90(mat, n);
	cout << endl;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j)
			cout << mat[i][j] << " ";
		cout << endl;
	}

	system("PAUSE");
	return 0;
}

