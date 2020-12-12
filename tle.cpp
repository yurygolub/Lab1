#include "pch.h"

void readFile(vector <string>& vector_string, string path)
{
	fstream fs;
	fs.open(path, fstream::in);
	if (!fs.is_open())
	{
		std::cout << "FileError" << endl;
	}
	else
	{
		string temp;
		//cout << "open" << endl;

		int i = 0;
		while (true)
		{
			getline(fs, temp);

			if (fs.eof())
			{
				break;
			}

			if (i == 3 || i == 12 || i == 13 || i == 14 || i == 17 || i == 18)
			{
				vector_string.push_back(temp);
				//cout << temp << endl;
			}				
			i++;
		}
	}
	fs.close();
	//cout << "close" << endl;
}

void writeToFile(string str, string path)
{
	fstream fs;
	fs.open(path, fstream::out | fstream::app);

	if (!fs.is_open())
	{
		std::cout << "FileError" << endl;
	}
	else
	{
		//cout << "open" << endl;

		fs << str << endl;

	}
	fs.close();
	//cout << "close" << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	string path;
	string path1 = "t1.txt";
	

	

	int count = 2;

	while (count <= 16)
	{
		vector <string>vector_string;

		path = "main_tab";

		if (count >= 10)
		{
			int tmp = count;
			char cha[2];
			cha[1] = tmp % 10 + '0';
			tmp /= 10;
			cha[0] = char(tmp) + '0';
			path.push_back(cha[0]);
			path.push_back(cha[1]);
		}
		else
		{
			int tmp = count;
			path.push_back(char(tmp) + '0');
		}

		path.append(".txt");

		readFile(vector_string, path);

		int space_count, tab_count;
		string result;

		// ================= 0я строка ============

		result.append("1 2020 07 17");

		space_count = 0;
		for (int j = 0; j < vector_string[0].size(); j++)
		{
			//cout << vector_string[0][j];
			if (vector_string[0][j] == ' ')
			{
				space_count++;
			}

			if (space_count == 7)
			{
				if (vector_string[0][j] == ':')
				{
					result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[0][j]);
			}
		}

		//cout << endl << "space_count : " << space_count << endl;
		//cout << endl;

		//cout << "result: " << result << endl;



		//============================ 1я, 2я, 3я строка ====================================


		int i = 0, j = 0, k = 0;
		int space_count_i = 0, space_count_j = 0, space_count_k = 0;
		int tab_count_i = 0, tab_count_j = 0, tab_count_k = 0;

		//================1 1===============

		for (; i < vector_string[1].size(); i++)
		{
			//cout << vector_string[1][j];
			if (vector_string[1][i] == ' ')
			{
				space_count_i++;
			}

			if (vector_string[1][i] == '\t')
			{
				tab_count_i++;
			}


			if (space_count_i == 2)
			{
				if (vector_string[1][i] == '°')
				{
					//result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[1][i]);
			}

			if (space_count_i == 3)
			{
				if (vector_string[1][i] == '\'')
				{
					//result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[1][i]);
			}

			if (space_count_i == 4)
			{
				if (vector_string[1][i] == '\"')
				{
					//result.push_back(' ');
					break;
				}
				result.push_back(vector_string[1][i]);
			}
		}



		//================2 1===============

		for (; j < vector_string[2].size(); j++)
		{
			if (vector_string[2][j] == ' ')
			{
				space_count_j++;
			}

			if (vector_string[2][j] == '\t')
			{
				tab_count_j++;
			}


			if (space_count_j == 4)
			{
				if (vector_string[2][j] == '°')
				{
					//result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[2][j]);
			}

			if (space_count_j == 5)
			{
				if (vector_string[2][j] == '\'')
				{
					//result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[2][j]);
			}

			if (space_count_j == 6)
			{
				if (vector_string[2][j] == '\"')
				{
					//result.push_back(' ');
					break;
				}
				result.push_back(vector_string[2][j]);
			}
		}



		//================3 1===============

		for (; k < vector_string[3].size(); k++)
		{
			if (vector_string[3][k] == ' ')
			{
				space_count_k++;
			}

			if (vector_string[3][k] == '\t')
			{
				tab_count_k++;
			}


			if (space_count_k == 4)
			{
				result.push_back(vector_string[3][k]);
			}

			if (space_count_k == 5)
			{
				break;
			}
		}



		//==================1 2=============

		for (; i < vector_string[1].size(); i++)
		{
			if (vector_string[1][i] == ' ')
			{
				space_count_i++;
			}

			if (vector_string[1][i] == '\t')
			{
				tab_count_i++;
			}


			if (tab_count_i == 2 && space_count_i == 9)
			{
				if (vector_string[1][i] == '°')
				{
					//result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[1][i]);
			}

			if (tab_count_i == 2 && space_count_i == 10)
			{
				if (vector_string[1][i] == '\'')
				{
					//result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[1][i]);
			}

			if (tab_count_i == 2 && space_count_i == 11)
			{
				if (vector_string[1][i] == '\"')
				{
					//result.push_back(' ');
					break;
				}
				result.push_back(vector_string[1][i]);
			}
		}



		//=================2 2=================

		for (; j < vector_string[2].size(); j++)
		{
			if (vector_string[2][j] == ' ')
			{
				space_count_j++;
			}

			if (vector_string[2][j] == '\t')
			{
				tab_count_j++;
			}


			if (tab_count_j == 2 && space_count_j == 10)
			{
				if (vector_string[2][j] == '°')
				{
					//result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[2][j]);
			}

			if (tab_count_j == 2 && space_count_j == 11)
			{
				if (vector_string[2][j] == '\'')
				{
					//result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[2][j]);
			}

			if (tab_count_j == 2 && space_count_j == 12)
			{
				if (vector_string[2][j] == '\"')
				{
					//result.push_back(' ');
					break;
				}
				result.push_back(vector_string[2][j]);
			}
		}



		//=================3 2=================

		for (; k < vector_string[3].size(); k++)
		{
			if (vector_string[3][k] == ' ')
			{
				space_count_k++;
			}

			if (vector_string[3][k] == '\t')
			{
				tab_count_k++;
			}

			if (tab_count_k == 2 && space_count_k == 19)
			{
				result.push_back(vector_string[3][k]);
			}

			if (tab_count_k == 2 && space_count_k == 20)
			{
				break;
			}
		}



		//=================1 3=================

		for (; i < vector_string[1].size(); i++)
		{
			if (vector_string[1][i] == ' ')
			{
				space_count_i++;
			}

			if (vector_string[1][i] == '\t')
			{
				tab_count_i++;
			}


			if (tab_count_i == 3 && space_count_i == 15)
			{
				if (vector_string[1][i] == 'h')
				{
					//result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[1][i]);
			}

			if (tab_count_i == 3 && space_count_i == 16)
			{
				if (vector_string[1][i] == 'm')
				{
					//result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[1][i]);
			}

			if (tab_count_i == 3 && space_count_i == 17)
			{
				if (vector_string[1][i] == 's')
				{
					//result.push_back(' ');
					break;
				}
				result.push_back(vector_string[1][i]);
			}
		}



		//================2 3==================

		for (; j < vector_string[2].size(); j++)
		{
			if (vector_string[2][j] == ' ')
			{
				space_count_j++;
			}

			if (vector_string[2][j] == '\t')
			{
				tab_count_j++;
			}


			if (tab_count_j == 3 && space_count_j == 19)
			{
				if (vector_string[2][j] == '°')
				{
					//result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[2][j]);
			}

			if (tab_count_j == 3 && space_count_j == 20)
			{
				if (vector_string[2][j] == '\'')
				{
					//result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[2][j]);
			}

			if (tab_count_j == 3 && space_count_j == 21)
			{
				if (vector_string[2][j] == '\"')
				{
					//result.push_back(' ');
					break;
				}
				result.push_back(vector_string[2][j]);
			}
		}

		//cout << endl << "space_count_j : " << space_count_j << endl;
		//cout << "tab_count_j : " << tab_count_j << endl;
		//cout << endl;

		//cout << "result: " << result << endl;




		// ================= 4я строка ============

		space_count = 0;

		for (int j = 0; j < vector_string[4].size(); j++)
		{
			//cout << vector_string[4][j];
			if (vector_string[4][j] == ' ')
			{
				space_count++;
			}

			if (space_count == 4)
			{
				if (vector_string[4][j] == ' ')
				{
					result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[4][j]);
			}
		}

		//cout << endl << "space_count : " << space_count << endl;
		//cout << "tab_count : " << tab_count << endl;
		//cout << endl;

		//cout << "result: " << result << endl;



		// ================= 5я строка ============

		space_count = 0;

		for (int j = 0; j < vector_string[5].size(); j++)
		{
			//cout << vector_string[5][j];
			if (vector_string[5][j] == ' ')
			{
				space_count++;
			}

			if (space_count == 9)
			{
				if (vector_string[5][j] == ' ')
				{
					result.push_back(' ');
					continue;
				}
				result.push_back(vector_string[5][j]);
			}
		}

		//cout << endl << "space_count : " << space_count << endl;
		//cout << "tab_count : " << tab_count << endl;
		//cout << endl;

		cout << "result: " << result << endl;

		writeToFile(result, path1);
		count++;
	}
	
}

