#include "Task.h"
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>

void SaveTasksToFile(const vector<Task>& tasks, const string& fileName)
{
	ofstream ostream(fileName);
	ostream << tasks.size() << '\n';

	for (const Task& task : tasks) {
		string description = task.description;
		std::replace(description.begin(), description.end(), ' ', '-');
	ostream << '\n' << description << ' ' << task.done;
	}
}

vector<Task> LoadTasksFromFile(const string& fileName)
{
	if (!std::filesystem::exists(fileName)) {
	
		return vector<Task>();
	}
	vector<Task> tasks;
	ifstream istream(fileName);

	int n;
	istream >> n;

	for (int i = 0; i < n; i++) {
		string description;
		bool done;

		istream >> description >> done;
		replace(description.begin(), description.end(), '_', ' ');
		tasks.push_back(Task{ description, done });
	}
	return tasks;
}
