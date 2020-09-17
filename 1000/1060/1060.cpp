#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Range{
private:
	int start, end, middle, current;

public:
	Range(int start, int end);
	bool operator <(const Range& a) const;
	bool incCurrent();
	int getCurrent();
	int getOpposite();
	int getNumOfUnlucky() const;
};

Range::Range(int start, int end){
	this->start = start;
	this->end = end;
	middle = (start+end) / 2;
	current = start+1;
}

bool Range::operator <(const Range& a) const{
	return getNumOfUnlucky() > a.getNumOfUnlucky();
}

bool Range::incCurrent(){
	if(current < middle){
		current++;
		return true;
	} else
		return false;
}

int Range::getCurrent(){
	return current;
}

int Range::getOpposite(){
	if(2 * current== start + end){
		return -1;
	}
	return start + end - current;
}

int Range::getNumOfUnlucky() const{
	return (current - start) * (end - start) - 1;
}

int main(){
	int l, n, temp, max = 0;
	vector<int> nums;
	priority_queue<Range> q;

	cin >> l;
	for (int i = 0; i < l; ++i){
		cin >> temp;
		if(max < temp) max = temp;
		nums.push_back(temp);
	}
	
	cin >> n;

	sort(nums.begin(), nums.end());

	for (int i = 0; i < l && n > 0; ++i){
		int start = i == 0 ? 0 : nums[i-1];
		int end = nums[i];

		if( start != 0 ){
			cout << start << " ";
			n--;

			if(n == 0)
				break;
		}

		if(end - start == 2){
			cout << start+1 << " ";
			n--;

			if(n == 0)
				break;
		} else if(end - start != 1)
			q.push(Range(start, end));

		if(end == max){
			cout << end << " ";
			n--;
		}
	}

	while(q.size() > 0 && n > 0){
		Range cur = q.top();
		q.pop();
		cout << cur.getCurrent() << " ";
		n--;
		
		if(n == 0){
			break;
		}

		if(cur.getOpposite() != -1){
			cout << cur.getOpposite() << " ";
			n--;
		}

		if(cur.incCurrent())
			q.push(cur);
	}

	for(int i = 1; i < n+1; ++i){
		cout << max + i << " ";
	}

	cout << endl;

	return 0;
}
