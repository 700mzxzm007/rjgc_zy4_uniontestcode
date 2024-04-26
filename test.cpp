#include "pch.h"
#include<gtest/gtest.h>
#include<vector>
#include"caulatekhint.h"

using namespace std;

vector<int>IntKhResult(vector<string>train, vector<int>state, vector<char>op) {
	vector<int>result;
	for (int i = 0; i < train.size(); i++) {
		result.push_back(evaluate(train[i]));
	}
	return result;
}


float roundToPrecision(float number, int precision) {
	float factor = pow(10.0, precision);
	return round(number * factor) / factor;

}
vector<float>FloatKhReult(vector<string>train, vector<int>state,vector<char>op) {
	vector<float>result;
	for (int i = 0; i < train.size(); i++) {

		result.push_back(roundToPrecision(evaluate(train[i]), state[5]));
	}
	return result;
}

vector<int>IntNKhResult(vector<string>train, vector<int>state, vector<char>op) {
	vector<int>result;
	for (int i = 0; i < train.size(); i++) {
		result.push_back(evaluate(train[i]));
	}
	return result;

}

vector<float>FloatNKhReult(vector<string>train, vector<int>state, vector<char>op) {
	vector<float>result;
	for (int i = 0; i < train.size(); i++) {

		result.push_back(roundToPrecision(evaluate(train[i]), state[5]));
	}
	return result;
}



//带括号的int类型计算结果计算
TEST(IntKhResult, Arraytest0) {
	vector<string>train = { "(36+25)-1","16+(17+70)","42-(50-37)" };
	vector<int>state = { 3,1,100,1,0,0 };
	vector<char>op = {'+', '-'};
	vector<int>ans = { 60,103,29 };
	EXPECT_EQ(IntKhResult(train, state,op), ans);
	EXPECT_TRUE(true);
}
TEST(IntKhResult, Arraytest1) {
	vector<string>train = { "(70-15)*6/3+12","6/(24*7)+38-7","(50-16)-31*3+68" };
	vector<int>state = { 3,1,100,1,0,0 };
	vector<char>op = { '+','-','*','/'};
	vector<int>ans = {122,31,9};
	EXPECT_EQ(IntKhResult(train, state, op), ans);
	EXPECT_TRUE(true);
}
TEST(IntKhResult, Arraytest2) {
	vector<string>train = { "(32+7)+6","(19+5)+62","30+(63+7)" };
	vector<int>state = { 3,1,100,1,0,0 };
	vector<char>op = { '+' };
	vector<int>ans = { 45,86,100 };
	EXPECT_EQ(IntKhResult(train, state, op), ans);
	EXPECT_TRUE(true);
}
TEST(IntKhResult, Arraytest3) {
	vector<string>train = { "(10+10)-10*10" };
	vector<int>state = { 1,10,10,1,0,0 };
	vector<char>op = { '+','-','*' };
	vector<int>ans = { -80 };
	EXPECT_EQ(IntKhResult(train, state, op), ans);
	EXPECT_TRUE(true);
}

//浮点数带括号
TEST(FloatKhReult, Arraytest4) {
	vector<string>train = { "8.0*(14.0/7.0)","30.0/(2.0*3.0)","40.0/(2.0*4.0)" };
	vector<int>state = { 1,10,10,1,0,0 };
	vector<char>op = { '*','/' };
	vector<float>ans = { 16.0,5.0,5.0 };
	EXPECT_EQ(FloatKhReult(train, state, op), ans);
	EXPECT_TRUE(true);
}



TEST(FloatKhReult, Arraytest5) {
	vector<string>train = { "9.6-3.6-1.0","26.7-13.5-6.2","18.2-5.7-2.2","46.5-8.7-5.0","38.2-10.0-6.7" };
	vector<int>state = { 5,1,50,0,1,1 };
	vector<char>op = { '-' };
	vector<float>ans = { 5.0,7.0,10.3,32.8,21.5 };
	EXPECT_EQ(FloatKhReult(train, state, op), ans);
	EXPECT_TRUE(true);
}


TEST(FloatKhReult, Arraytest6) {
	vector<string>train = { "(80.0/2.0)/2.0","(25.0 / 1.0) / 5.0" };
	vector<int>state = { 2,5,80,1,1,1 };
	vector<char>op = { '/' };
	vector<float>ans = { 20.0,5.0 };
	EXPECT_EQ(FloatKhReult(train, state, op), ans);
	EXPECT_TRUE(true);
}

TEST(FloatKhReult, Arraytest7) {
	vector<string>train = { "(10.0*10.0)-10.0","10.0+10.0/10.0" };
	vector<int>state = { 2,10,10,1,1,1 };
	vector<char>op = { '+','-','*','/' };
	vector<float>ans = { 90.0,11.0 };
	EXPECT_EQ(FloatKhReult(train, state, op), ans);
	EXPECT_TRUE(true);
}

//不带括号的int型
TEST(IntNKhResult, Arraytest8) {
	vector<string>train = { "32+18","70-16","50+60","41-35" };
	vector<int>state = { 5,10,60,0,0,0 };
	vector<char>op =  { '+','-' };
	vector<int>ans = { 50,54,110,6 };
	EXPECT_EQ(IntNKhResult(train, state, op), ans);
	EXPECT_TRUE(true);
}
TEST(IntNKhResult, Arraytest9) {
	vector<string>train = { "32*11","20*26","53*35","40*31" };
	vector<int>state = { 4,10,60,0,0,0 };
	vector<char>op = { '*' };
	vector<int>ans = { 352,520,1855,1240 };
	EXPECT_EQ(IntNKhResult(train, state, op), ans);
	EXPECT_TRUE(true);
}
TEST(IntNKhResult, Arraytest10) {
	vector<string>train = { "10+10" };
	vector<int>state = { 1,10,10,0,0,0 };
	vector<char>op = { '+' };
	vector<int>ans = { 20 };
	EXPECT_EQ(IntNKhResult(train, state, op), ans);
	EXPECT_TRUE(true);
}

TEST(IntNKhResult, Arraytest11) {
	vector<string>train = { "10+10-10*10" };
	vector<int>state = { 1,10,10,0,0,0 };
	vector<char>op = { '+','-','*' };
	vector<int>ans = { -80 };
	EXPECT_EQ(IntNKhResult(train, state, op), ans);
	EXPECT_TRUE(true);
}

TEST(IntNKhResult, Arraytest12) {
	vector<string>train = { "10/10*10" };
	vector<int>state = { 1,10,10,0,0,0 };
	vector<char>op = { '*','/' };
	vector<int>ans = { 10 };
	EXPECT_EQ(IntNKhResult(train, state, op), ans);
	EXPECT_TRUE(true);
}

TEST(IntNKhResult, Arraytest13) {
	vector<string>train = { "10*10/10-10+10" };
	vector<int>state = { 1,10,10,0,0,0 };
	vector<char>op = { '+','-','*','/' };
	vector<int>ans = { 10 };
	EXPECT_EQ(IntNKhResult(train, state, op), ans);
	EXPECT_TRUE(true);
}

//不带括号
TEST(FloatNKhReult, Arraytest14) {
vector<string>train = { "26.0*20.0","0/5.89","6.00/3.00","11.0*47.0" };
vector<int>state = { 4,1,50,0,1,2 };
vector<char>op = { '*','/' };
vector<float>ans = { 520.0,0.0,2.0,517.0};
EXPECT_EQ(FloatNKhReult(train, state, op), ans);
EXPECT_TRUE(true);
}

TEST(FloatNKhReult, Arraytest15) {
	vector<string>train = { "10.00/10.00" };
	vector<int>state = { 1,10,10,0,1,2 };
	vector<char>op = { '/' };
	vector<float>ans = { 1.00 };
	EXPECT_EQ(FloatNKhReult(train, state, op), ans);
	EXPECT_TRUE(true);
}



int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}