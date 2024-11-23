	#include <unordered_map>

	class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			
			for(auto line: board) {
				unordered_map<char, int> g_line;
				for(char pos: line) {
					if(pos == '.') {
						continue;
					}
					
					++g_line[pos];
					if(g_line[pos] > 1) {
						return false;
					}
				}
			}
			
			for(int line = 0; line < 9; ++line) {
				unordered_map<int, int> v_line;
				for(int i = 0; i < 9; ++i) {
					if(board[i][line] == '.') {
						continue;
					}
					
					++v_line[board[i][line]];
					if(v_line[board[i][line]] > 1) {
						return false;
					}
				}
			}
			
			// Решал на таймер, и понимая что не могу придумать цикл для обхода квадрата
			// начал в прямую переберать элементы
			for(int i = 0; i < 9; i+=3) {
				unordered_map<int, int> box; // <-- Ошибка, надо объявлять в следующем цикле
				for(int j = 0; j < 9; j+=3) {
					box[board[i][j]]++;
					box[board[i][j + 1]]++;
					box[board[i][j + 2]]++;
					box[board[i + 1][j]]++;
					box[board[i + 1][j + 1]]++;
					box[board[i + 1][j + 2]]++;
					box[board[i + 2][j]]++;
					box[board[i + 2][j + 1]]++;
					box[board[i + 2][j + 2]]++;
					
					for(auto b: box) {
						if(b.first == '.') {
							continue;
						}
						
						if(b.second != 1) {
							return false;
						}
						
					}
				}
			}
			
			return true;
		}
	};