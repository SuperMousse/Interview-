// 剑指offer解法: 动态规划, 循环

int GetTranslationCount(int number) {
	if (number < 1) {
		return 0;
	}
	string numberInString = to_string(number);
	return GetTranslationCountCount(numberInString);
}


int GetTranslationCountCount(const string& number) {
	int length = number.size();
	int* counts = new int[length];
	memset(counts, 0, sizeof(counts));
	int count = 0;
	
	for (int i = length - 1; i >= 0; --i) {
		count = 0;
		if (i < length - 1) {
			count = counts[i + 1]; // f(i+1)
		}
		else {
			count = 1; // 考虑单个字母本身
		}

		if (i < length - 1) {
			int digit1 = number[i] - '0';
			int digit2 = number[i + 1] - '0';
			int converted = digit1 * 10 + digit2;
			if (converted >= 10 && converted <= 25) {
				if (i < length - 2) { 
					count += counts[i + 2]; // 至少倒数第三位开始才包括f(i+2)
				}
				else {
					count += 1; // 倒数第二位至多将最后两位的组合+1
				}
			}
		}
		counts[i] = count;
	}

	count = counts[0];
	delete[] counts;

	return count;
}



// 拓展解法: 递归
