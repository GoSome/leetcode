#include<io.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;



void getFiles(string path, vector<string>& files)
{
	//�ļ����  
	long   hFile = 0;
	//�ļ���Ϣ  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//�����Ŀ¼,����֮  
			//�������,�����б�  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				//if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				//	getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

int main(){
	char * filePath = "g:\\leetcode";
	vector<string> files;
	getFiles(filePath, files);
	for (int i = 0; i < files.size(); i++){
		string tmp = files[i];
		cout << files[i].erase(files[i].find_last_of('.')) << " | [" << tmp << "](\\" << tmp << ")" << endl;
	}

}
