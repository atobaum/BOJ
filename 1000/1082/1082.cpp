#include <iostream>

using namespace std;

int N, money;
int price[10], ans[51];
int min_price = 100; // 최저 가격
int min_number;

// money 이하의 0 제외한 최소 가격의 숫자 반환
int get_number_of_minimum_price_other_than_zero() {
  int index = -1;
  int min_price = 100;
  for (int i = 1; i < N; i++) {
    if (price[i] <= money && price[i] <= min_price) {
      min_price = price[i];
      index = i;
    }
  }

  return index;
}

int get_index_of_maximum_num(int p) {
  int index = -1;
  for (int i = 0; i < N; i++) {
    if (price[i] <= p)
      index = i;
  }

  return index;
}

int main() {
  fill_n(ans, 51, -1);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> price[i];
    if (price[i] <= min_price) {
      min_price = price[i];
      min_number = i;
    }
  }
  cin >> money;

  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }

  // 첫째자리는 0제외 최저
  int num = get_number_of_minimum_price_other_than_zero();
  if (num == -1) {
    cout << 0 << endl;
    return 0;
  }
  ans[0] = num;
  money -= price[num];

  int idx = 0;
  while (money >= min_price) {
    idx++;
    ans[idx] = min_number;
    money -= min_price;
  }

  // 최적화
  for (int idx = 0; ans[idx] != -1; ++idx) {
    num = get_index_of_maximum_num(money + price[ans[idx]]);
    if (num == -1)
      break;

    money -= price[num] - price[ans[idx]];
    ans[idx] = num;
  }

  for (int idx = 0; ans[idx] != -1; ++idx) {
    cout << ans[idx];
  }
  cout << endl;
  return 0;
}