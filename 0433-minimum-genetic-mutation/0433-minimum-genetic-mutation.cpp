class Solution {
public:

    
  int minMutation(string start, string end, vector<string>& bank) {
	int n = start.size();
	queue <pair<string, int>> q;
	q.push({start, 0});

	set<string> visited;
	set<string> nodes(bank.begin(), bank.end());
	string t = "ACGT";

	if (nodes.count(end) == 0) return -1;


	while (!q.empty()) {

		pair<string, int> top = q.front();
		q.pop();

		if (top.first == end) {
			return top.second;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 4; j++) {
				string temp = top.first;
				if (temp[i] != t[j]) {
					temp[i] = t[j];
					if (nodes.count(temp) != 0 && visited.count(temp) == 0) {
						q.push({temp, top.second + 1});

					}

				}

			}
		}

	}

	return -1;

}
};