//Cho dãy số A[] gồm n số nguyên dương.Tam giác đặc biệt của dãy số A[] là tam giác được tạo ra bởi n hàng, trong đó hàng thứ 1 là dãy số A[], 
// hàng i là tổng hai phần tử liên tiếp của hàng i - 1 (2 ≤ i ≤ n).Ví dụ A[] = { 1, 2, 3, 4, 5 }, khi đó tam giác được tạo nên như dưới đây :
//[1, 2, 3, 4, 5]
// [3, 5, 7, 9] 
// [8, 12, 16] 
// [20, 28] 
// [48]
//

#include <iostream>
using namespace std;
#define MAX 100

void Solution()
{
	cout << "Xin moi nhap so luong: ";
	int n; cin >> n;
	const int val = n + 1;
	int arr[MAX][MAX];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[0][i];
	}

	int col = n - 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j + 1];
			
		}
		--col;
	}

	col = n;

	for (int i = 0; i < n; i++)
	{
		cout << "[";
		for (int j = 0; j < col; j++)
		{
			if (j == col-1) cout << arr[i][j];
			else
			{
				cout << arr[i][j] << " ,";
			}
			
		}
		cout << "]" << endl;
		--col;
	}
}

int main()
{

	Solution();
	return 0;
}