#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include<random>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include <iomanip>
using namespace std;


int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

float applyOp(float a, float b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/':
		if (b == 0) throw std::runtime_error("Cannot divide by zero.");
		return a / b;
	default: return 0;
	}
}

float evaluate(const std::string& s) {
	std::stack<float> values;
	std::stack<char> ops;

	for (size_t i = 0; i < s.length(); i++) {
		if (s[i] == ' ') continue;

		if (s[i] == '(') {
			ops.push(s[i]);
		}
		else if (isdigit(s[i]) || s[i] == '.') {
			float value = 0;
			int decimal = 0;
			while (i < s.length() && (isdigit(s[i]) || s[i] == '.')) {
				if (s[i] == '.') {
					decimal = 1;
					i++;
					continue;
				}
				value = value * 10 + (s[i] - '0');
				if (decimal) decimal *= 10;
				i++;
			}
			if (decimal) value /= decimal;
			values.push(value);
			i--;
		}
		else if (s[i] == ')') {
			while (!ops.empty() && ops.top() != '(') {
				float val2 = values.top();
				values.pop();
				float val1 = values.top();
				values.pop();
				char op = ops.top();
				ops.pop();
				values.push(applyOp(val1, val2, op));
			}
			if (!ops.empty()) ops.pop(); // Remove '('
		}
		else {
			while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
				float val2 = values.top();
				values.pop();
				float val1 = values.top();
				values.pop();
				char op = ops.top();
				ops.pop();
				values.push(applyOp(val1, val2, op));
			}
			ops.push(s[i]);
		}
	}

	while (!ops.empty()) {
		float val2 = values.top();
		values.pop();
		float val1 = values.top();
		values.pop();
		char op = ops.top();
		ops.pop();
		values.push(applyOp(val1, val2, op));
	}

	return values.top();
}

