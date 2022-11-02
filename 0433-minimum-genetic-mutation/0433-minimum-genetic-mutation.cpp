class Solution {
public:

 

int minMutation(string start, string end, vector<string>& bank) {
	int n = start.size();
	vector <pair<string, int>> q;
	q.push_back({start, 0});

	set<string> visited;
	set<string> nodes(bank.begin(), bank.end());
	string t = "ACGT";

	if (nodes.count(end) == 0) return -1;

	int i = 0;

	while (i < q.size()) {

		pair<string, int> top = q[i];
		i++;

		if (top.first == end) {
			return top.second;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 4; j++) {
				string temp = top.first;
				if (temp[i] != t[j]) {
					temp[i] = t[j];
					if (nodes.count(temp) != 0 && visited.count(temp) == 0) {
						q.push_back({temp, top.second + 1});

					}

				}

			}
		}

	}

	return -1;

}
};