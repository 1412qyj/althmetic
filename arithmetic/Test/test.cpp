#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test1)
		{
			// TODO:  在此输入测试代码

			//成功测试
			LPSTR p_array = new char[MAX_PATH];
			int i_key = 0;
			LPSTR p_output = new char[MAX_PATH];
			
			GetPrivateProfileStringA("test1", "Array", "", p_array, MAX_PATH, INI_PATH_1);
			i_key = GetPrivateProfileIntA("test1", "Key", 0, INI_PATH_1);
			GetPrivateProfileStringA("test1", "Output", "", p_output, MAX_PATH, INI_PATH_1);

			vector<int> nums;

			stringstream sstr;
			int tmp;

			sstr << p_array;

			while (sstr >> tmp)
			{
				nums.push_back(tmp);
			}

			bool result;

			result = !strncmp(p_output, "true", 4) ? true : false;

			if (result)
			{
				Assert::IsTrue(ContainsNearbyDuplicate(nums, i_key));
			}
			else
			{
				Assert::IsFalse(ContainsNearbyDuplicate(nums, i_key));
			}

			//失败测试
			GetPrivateProfileStringA("test1", "Array1", "", p_array, MAX_PATH, INI_PATH_1);
			i_key = GetPrivateProfileIntA("test1", "Key1", 0, INI_PATH_1);
			GetPrivateProfileStringA("test1", "Output1", "", p_output, MAX_PATH, INI_PATH_1);

			sstr.clear();
			nums.clear();

			sstr << p_array;

			while (sstr >> tmp)
			{
				nums.push_back(tmp);
			}

			result = !strncmp(p_output, "true", 4) ? true : false;

			if (result)
			{
				Assert::IsTrue(ContainsNearbyDuplicate(nums, i_key));
			}
			else
			{
				Assert::IsFalse(ContainsNearbyDuplicate(nums, i_key));
			}
		}

		TEST_METHOD(Test2)
		{
			// TODO:  在此输入测试代码
			//测试一
			int input = 0;
			LPSTR p_output = new char[MAX_PATH];
			string strRet;

			input = GetPrivateProfileIntA("test2", "input", 0, INI_PATH_2);
			GetPrivateProfileStringA("test2", "output", "", p_output, MAX_PATH, INI_PATH_2);
			strRet = ExcelSheetColumnTitle(input);

			Assert::AreEqual(0, strcmp(strRet.c_str(), p_output));


			//测试二
			strRet.clear();
			LPSTR p_output1 = new char[MAX_PATH];

			int input1 = GetPrivateProfileIntA("test2", "Input1", 0, INI_PATH_2);
			GetPrivateProfileStringA("test2", "Output1", "", p_output1, MAX_PATH, INI_PATH_2);
			strRet = ExcelSheetColumnTitle(input1);

			Assert::AreEqual(0, strcmp(strRet.c_str(), p_output1));

			//free(p_ret);
		}

		TEST_METHOD(Test3)
		{
			// TODO:  在此输入测试代码
			int input = 0;
			LPSTR p_output = new char[MAX_PATH];
			bool flag;

			input = GetPrivateProfileIntA("test3", "input", 6, INI_PATH_3);
			GetPrivateProfileStringA("test3", "output", "", p_output, MAX_PATH, INI_PATH_3);

			flag = (strncmp(p_output, "true", 4) == 0) ? true : false;

			Assert::AreEqual(flag, IsUgly(input));

			input = GetPrivateProfileIntA("test3", "Input1", 0, INI_PATH_3);
			GetPrivateProfileStringA("test3", "Output1", "", p_output, MAX_PATH, INI_PATH_3);

			flag = (strncmp(p_output, "true", 4) == 0) ? true : false;
			Assert::AreEqual(flag, IsUgly(input));

			input = GetPrivateProfileIntA("test3", "Input2", 0, INI_PATH_3);
			GetPrivateProfileStringA("test3", "Output2", "", p_output, MAX_PATH, INI_PATH_3);

			flag = (strncmp(p_output, "true", 4) == 0) ? true : false;
			Assert::AreEqual(flag, IsUgly(input));

			input = GetPrivateProfileIntA("test3", "Input3", 0, INI_PATH_3);
			GetPrivateProfileStringA("test3", "Output3", "", p_output, MAX_PATH, INI_PATH_3);

			flag = (strncmp(p_output, "true", 4) == 0) ? true : false;
			Assert::AreEqual(flag, IsUgly(input));
		}

		TEST_METHOD(Test4)
		{
			// TODO:  在此输入测试代码
			int input = GetPrivateProfileIntA("test4", "Input", 0, INI_PATH_4);

			LPSTR p_output = new char[5];

			GetPrivateProfileStringA("test4", "Output", "", p_output, 5, INI_PATH_4);

			bool flag = (strncmp(p_output, "true", 4) == 0) ? true : false;

			Assert::AreEqual(flag, IsPalindrome(input));

			//==================================

			input = GetPrivateProfileIntA("test4", "Input1", 0, INI_PATH_4);
			GetPrivateProfileStringA("test4", "Output1", "", p_output, 5, INI_PATH_4);

			flag = (strncmp(p_output, "true", 4) == 0) ? true : false;

			Assert::AreEqual(flag, IsPalindrome(input));


		}


		TEST_METHOD(Test5)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];

			GetPrivateProfileStringA("test5", "Input", "", p_input, MAX_PATH, INI_PATH_5);

			int ioutput = GetPrivateProfileIntA("test5", "Output", 0, INI_PATH_5);

			stringstream sstr(p_input);

			int inums[MAX_PATH];
			char tmp[10];
			int i = 0;

			while (sstr >> tmp)
			{
				if (!strncmp(tmp, "null", 4))
				{
					inums[i] = -1;
					i++;
					continue;
				}

				inums[i] = atoi(tmp);

				i++;
			}

			TreeNode *p_tree = CreateTree(inums, 0, i);

			Assert::AreEqual(ioutput, MinDepth(p_tree));

			//============================================
			free(p_tree);
			p_tree = nullptr;

			GetPrivateProfileStringA("test5", "Input1", "", p_input, MAX_PATH, INI_PATH_5);

			ioutput = GetPrivateProfileIntA("test5", "Output1", 0, INI_PATH_5);

			memset(inums, 0, sizeof(int) * MAX_PATH);

			stringstream sstr1(p_input);

			while (sstr1 >> tmp)
			{
				if (!strncmp(tmp, "null", 4))
				{
					inums[i] = -1;
				}

				inums[i] = atoi(tmp);

				i++;
			}

			//p_tree = CreateTree(inums, 0, i);
			int array[] = { 1, 2, 4, -1, 3, 5, -1, -1, -1, -1, -1 };
			p_tree = CreateTree(array, 0, sizeof(array) / sizeof(int));
			Assert::AreEqual(ioutput, MinDepth(p_tree));

			//================================================

			Assert::AreEqual(0, MinDepth(nullptr));

		}


		TEST_METHOD(Test6)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			LPSTR p_output = new char[6];

			GetPrivateProfileStringA("test6", "Input", "", p_input, MAX_PATH, INI_PATH_6);
			GetPrivateProfileStringA("test6", "Output", "", p_output, 6, INI_PATH_6);

			stringstream sstr;
			int inums[MAX_PATH];
			char tmp[10];
			int size = 0;
			int i = 0;

			sstr << p_input;

			while (sstr >> tmp)
			{
				inums[i++] = atoi(tmp);
				size++;
			}

			vector<int> ivector_input;

			for (i = 0; i < size; i++)
			{
				ivector_input.push_back(inums[i]);
			}

			bool boutput = (strncmp("true", p_output, 4) == 0) ? true : false;

			Assert::AreEqual(boutput, ContainsDuplicate(ivector_input));

			//===================================================================
			GetPrivateProfileStringA("test6", "Input1", "", p_input, MAX_PATH, INI_PATH_6);
			GetPrivateProfileStringA("test6", "Output1", "", p_output, 6, INI_PATH_6);

			stringstream sstr1(p_input);

			memset(inums, 0, sizeof(int) * MAX_PATH);
			i = 0;
			size = 0;
			while (sstr1 >> tmp)
			{
				inums[i++] = atoi(tmp);
				size++;
			}

			ivector_input.clear();

			for (i = 0; i < size; i++)
			{
				ivector_input.push_back(inums[i]);
			}

			boutput = (strncmp("true", p_output, 4) == 0) ? true : false;

			Assert::AreEqual(boutput, ContainsDuplicate(ivector_input));
		}

		TEST_METHOD(Test7)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];

			GetPrivateProfileStringA("test7", "Input", "", p_input, MAX_PATH, INI_PATH_7);
			int ioutput = GetPrivateProfileIntA("test7", "Output", 0, INI_PATH_7);

			stringstream sstr;

			sstr << p_input;
			int inums[MAX_PATH];
			int size = 0;
			char tmp[10];

			while (sstr >> tmp)
			{
				if (!strncmp(tmp, "null", 4))
				{
					inums[size] = -1;
				}
				else
				{
					inums[size] = atoi(tmp);
				}

				size++;
			}

			//创建二叉树
			TreeNode *p_tree = CreateTree(inums, 0, size);

			Assert::AreEqual(ioutput, MaxDepth(p_tree));

		}


		TEST_METHOD(Test8)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];

			GetPrivateProfileStringA("test8", "Input", "", p_input, MAX_PATH, INI_PATH_8);			
			GetPrivateProfileStringA("test8", "Input", "", p_input, MAX_PATH, INI_PATH_8);
			GetPrivateProfileStringA("test8", "Output", "", p_output, MAX_PATH, INI_PATH_8);

			stringstream sstr_in(p_input);
			stringstream sstr_out(p_output);
			int iinput[MAX_PATH];
			int ioutput[MAX_PATH];
			char tmp[10];
			int size = 0;

			while (sstr_in >> tmp)
			{
				iinput[size++] = atoi(tmp);
			}

			size = 0;

			while (sstr_out >> tmp)
			{
				ioutput[size++] = atoi(tmp);
			}

			for (int i = 0; i < size; i++)
			{
				Assert::AreEqual(ioutput[i], HammingWeight(iinput[i]));
			}

		}


		TEST_METHOD(Test9)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input_1 = new char[MAX_PATH];
			LPSTR p_input_2 = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];


			GetPrivateProfileStringA("test9", "Input1", "", p_input_1, MAX_PATH, INI_PATH_9);
			GetPrivateProfileStringA("test9", "Input2", "", p_input_2, MAX_PATH, INI_PATH_9);
			GetPrivateProfileStringA("test9", "Output", "", p_output, MAX_PATH, INI_PATH_9);


			stringstream sstr1(p_input_1), sstr2(p_input_2), sstr3(p_output);
			string str1, str2, str3;


			while (sstr1 >> str1 && sstr2 >> str2 && sstr3 >> str3)
			{
				Assert::AreEqual(str3, AddBinary(str1, str2));

				str1.clear();
				str2.clear();
				str3.clear();
			}
		}


		TEST_METHOD(Test10)
		{
			// TODO:  在此输入测试代码
			char *pIn = new char[MAX_PATH];
			char *pOut = new char[MAX_PATH];

			GetPrivateProfileStringA("test10", "Input", "", pIn, MAX_PATH, INI_PATH_10);
			GetPrivateProfileStringA("test10", "Output", "", pOut, MAX_PATH, INI_PATH_10);

			stringstream sstrIn;
			stringstream sstrOut;

			sstrIn << pIn;
			sstrOut << pOut;

			int size = 0;
			int nums[MAX_PATH];
			vector<string> vecStrOut;
			string strTmp;

			while (sstrOut >> strTmp)
			{
				vecStrOut.push_back(strTmp);
			}

			while (sstrIn >> strTmp)
			{
				if (!strncmp("null", strTmp.c_str(), 4))
				{
					nums[size] = -1;
				}
				else
				{
					nums[size] = atoi(strTmp.c_str());
				}

				size++;
			}

			TreeNode *pTree = CreateTree(nums, 0, size);

			vector<string> vecRet = BinaryTreePaths(pTree);

			bool bResult = (vecRet == vecStrOut) ? true : false;

			Assert::IsTrue(bResult);
		}


		TEST_METHOD(Test11)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];

			GetPrivateProfileStringA("test11", "Input", "", p_input, MAX_PATH, INI_PATH_11);
			GetPrivateProfileStringA("test11", "Output", "", p_output, MAX_PATH, INI_PATH_11);

			stringstream sstr_in(p_input);
			stringstream sstr_out(p_output);

			char flag[10];
			char nums[5];
			bool b_output;

			while (sstr_out)
			{
				sstr_out >> flag;
				sstr_in >> nums;

				b_output = (!strncmp(flag, "true", 4)) ? true : false;

				Assert::AreEqual(b_output, CanWinNim(atoi(nums)));
			}

		}


		TEST_METHOD(Test12)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];

			GetPrivateProfileStringA("test12", "Input", "", p_input, MAX_PATH, INI_PATH_12);
			GetPrivateProfileStringA("test12", "Output", "", p_output, MAX_PATH, INI_PATH_12);

			stringstream sstr_input(p_input);
			stringstream sstr_output(p_output);

			char p_flag[6];
			char p_symbols[MAX_PATH];
			bool b_flag = false;

			while (sstr_input)
			{
				sstr_input >> p_symbols;
				sstr_output >> p_flag;

				b_flag = (!strncmp(p_flag, "true", 4)) ? true : false;

				Assert::AreEqual(b_flag, IsValid(p_symbols));

				memset(p_symbols, 0, MAX_PATH);
				memset(p_flag, 0, 6);
			}

		}


		TEST_METHOD(Test13)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];

			GetPrivateProfileStringA("test13", "Input", "", p_input, MAX_PATH, INI_PATH_13);
			GetPrivateProfileStringA("test13", "Output", "", p_output, MAX_PATH, INI_PATH_13);

			stringstream sstr_in(p_input);
			stringstream sstr_out(p_output);

			char ch_nums[200];
			int num;

			while (sstr_in >> ch_nums && sstr_out >> num)
			{
				Assert::AreEqual(num, MyAtoi(ch_nums));
			}

		}

		TEST_METHOD(Test14)
		{
			// TODO:  在此输入测试代码

			LPSTR p_input = new char[MAX_PATH];
			GetPrivateProfileStringA("test14", "Input", "", p_input, MAX_PATH, INI_PATH_14);

			int i_output = GetPrivateProfileIntA("test14", "Output", 0, INI_PATH_14);

			stringstream sstr_input;

			sstr_input << p_input;

			int tmp;

			vector<int> vec;

			while (sstr_input >> tmp)
			{
				vec.push_back(tmp);
			}

			Assert::AreEqual(i_output, SingleNumber(vec));

			memset(p_input, 0, MAX_PATH);

			GetPrivateProfileStringA("test14", "Input1", "", p_input, MAX_PATH, INI_PATH_14);

			i_output = GetPrivateProfileIntA("test14", "Output1", 0, INI_PATH_14);

			sstr_input.clear();

			sstr_input << p_input;

			vec.clear();

			while (sstr_input >> tmp)
			{
				vec.push_back(tmp);
			}

			Assert::AreEqual(i_output, SingleNumber(vec));


			GetPrivateProfileStringA("test14", "Input2", "", p_input, MAX_PATH, INI_PATH_14);

			i_output = GetPrivateProfileIntA("test14", "Output2", 0, INI_PATH_14);

			sstr_input.clear();

			sstr_input << p_input;

			vec.clear();

			while (sstr_input >> tmp)
			{
				vec.push_back(tmp);
			}

			Assert::AreEqual(i_output, SingleNumber(vec));


			//=========================================
			vector<int> vectmp;
			vectmp.push_back(1);

			Assert::AreEqual(vectmp[0], SingleNumber(vectmp));
		}


		TEST_METHOD(Test15)
		{
			// TODO:  在此输入测试代码
			//正确的测试
			LPSTR p_pattern_1 = new char[MAX_PATH];
			LPSTR p_string_1 = new char[MAX_PATH];
			LPSTR p_result_1 = new char[6];

			GetPrivateProfileStringA("test15", "Pattern1", "", p_pattern_1, MAX_PATH, INI_PATH_15);
			GetPrivateProfileStringA("test15", "String1", "", p_string_1, MAX_PATH, INI_PATH_15);
			GetPrivateProfileStringA("test15", "Result1", "", p_result_1, 6, INI_PATH_15);

			bool b_result_1 = (!strncmp(p_result_1, "true", 4)) ? true : false;

			Assert::AreEqual(b_result_1, WordPattern(p_pattern_1, p_string_1));

			//测试pattern和string的个数不一致
			LPSTR p_pattern_2 = new char[MAX_PATH];
			LPSTR p_string_2 = new char[MAX_PATH];
			LPSTR p_result_2 = new char[6];
			GetPrivateProfileStringA("test15", "Pattern2", "", p_pattern_2, MAX_PATH, INI_PATH_15);
			GetPrivateProfileStringA("test15", "String2", "", p_string_2, MAX_PATH, INI_PATH_15);
			GetPrivateProfileStringA("test15", "Result2", "", p_result_2, 6, INI_PATH_15);

			bool b_result_2 = (!strncmp(p_result_2, "true", 4)) ? true : false;

			Assert::AreEqual(b_result_2, WordPattern(p_pattern_2, p_string_2));

			//测试pattern和string不匹配
			LPSTR p_pattern_3 = new char[MAX_PATH];
			LPSTR p_string_3 = new char[MAX_PATH];
			LPSTR p_result_3 = new char[6];
			GetPrivateProfileStringA("test15", "Pattern3", "", p_pattern_3, MAX_PATH, INI_PATH_15);
			GetPrivateProfileStringA("test15", "String3", "", p_string_3, MAX_PATH, INI_PATH_15);
			GetPrivateProfileStringA("test15", "Result3", "", p_result_3, 6, INI_PATH_15);

			bool b_result_3 = (!strncmp(p_result_3, "true", 4)) ? true : false;

			Assert::AreEqual(b_result_3, WordPattern(p_pattern_3, p_string_3));

			LPSTR p_pattern_4 = new char[MAX_PATH];
			LPSTR p_string_4 = new char[MAX_PATH];
			LPSTR p_result_4 = new char[6];
			GetPrivateProfileStringA("test15", "Pattern4", "", p_pattern_4, MAX_PATH, INI_PATH_15);
			GetPrivateProfileStringA("test15", "String4", "", p_string_4, MAX_PATH, INI_PATH_15);
			GetPrivateProfileStringA("test15", "Result4", "", p_result_4, 6, INI_PATH_15);

			bool b_result_4 = (!strncmp(p_result_4, "true", 4)) ? true : false;

			Assert::AreEqual(b_result_4, WordPattern(p_pattern_4, p_string_4));

		}

		TEST_METHOD(Test16)
		{
			// TODO:  在此输入测试代码
			uint32_t ui32_input = GetPrivateProfileIntA("test16", "Input1", 0, INI_PATH_16);
			uint32_t ui32_output = GetPrivateProfileIntA("test16", "Output2", 0, INI_PATH_16);

			Assert::AreEqual(ui32_output, ReverseBits(ui32_input));
		}


		TEST_METHOD(Test17)
		{
			// TODO:  在此输入测试代码
			/*test 1*/
			LPSTR p_input1 = new char[MAX_PATH];
			LPSTR p_input2 = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];

			GetPrivateProfileStringA("test17", "Input1", "", p_input1, MAX_PATH, INI_PATH_17);
			GetPrivateProfileStringA("test17", "Input2", "", p_input2, MAX_PATH, INI_PATH_17);
			GetPrivateProfileStringA("test17", "Output", "", p_output, MAX_PATH, INI_PATH_17);

			stringstream sstr;
			bool b_output;

			sstr << p_input2;

			char tmp[10];
			vector<string> vec_input2;

			while (sstr >> tmp)
			{
				vec_input2.push_back(tmp);
			}

			b_output = (strncmp(p_output, "true", 4)) ? false : true;

			Assert::AreEqual(b_output, WordBreak(p_input1, vec_input2));


			/*test 2*/
			GetPrivateProfileStringA("test17", "Input3", "", p_input1, MAX_PATH, INI_PATH_17);
			GetPrivateProfileStringA("test17", "Input4", "", p_input2, MAX_PATH, INI_PATH_17);
			GetPrivateProfileStringA("test17", "Output1", "", p_output, MAX_PATH, INI_PATH_17);

			sstr.clear();
			sstr << p_input2;

			vec_input2.clear();
			while (sstr >> tmp)
			{
				vec_input2.push_back(tmp);
			}

			b_output = (strncmp(p_output, "true", 4)) ? false : true;

			Assert::AreEqual(b_output, WordBreak(p_input1, vec_input2));

			/*test 3*/
			GetPrivateProfileStringA("test17", "Input5", "", p_input1, MAX_PATH, INI_PATH_17);
			GetPrivateProfileStringA("test17", "Input6", "", p_input2, MAX_PATH, INI_PATH_17);
			GetPrivateProfileStringA("test17", "Output2", "", p_output, MAX_PATH, INI_PATH_17);

			sstr.clear();
			sstr << p_input2;

			vec_input2.clear();
			while (sstr >> tmp)
			{
				vec_input2.push_back(tmp);
			}

			b_output = (strncmp(p_output, "true", 4)) ? false : true;

			Assert::AreEqual(b_output, WordBreak(p_input1, vec_input2));
		}



		TEST_METHOD(Test18)
		{
			// TODO:  在此输入测试代码
			LPSTR p_input = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];

			GetPrivateProfileStringA("test18", "Input", "", p_input, MAX_PATH, INI_PATH_18);
			GetPrivateProfileStringA("test18", "Output", "", p_output, MAX_PATH, INI_PATH_18);

			stringstream sstr_in;
			stringstream sstr_out;
			bool b_ret;

			sstr_in << p_input;
			sstr_out << p_output;

			vector<int> vec_in;
			vector<int> vec_out;

			int tmp = 0;


			while (sstr_in >> tmp)
			{
				vec_in.push_back(tmp);
			}

			while (sstr_out >> tmp)
			{
				vec_out.push_back(tmp);
			}
			vector<int> vec_ret = PlusOne(vec_in);
			b_ret = (vec_ret == vec_out) ? true : false;

			Assert::IsTrue(b_ret);

			//====================================================
			GetPrivateProfileStringA("test18", "Input1", "", p_input, MAX_PATH, INI_PATH_18);
			GetPrivateProfileStringA("test18", "Output1", "", p_output, MAX_PATH, INI_PATH_18);

			stringstream sstr_in1;
			stringstream sstr_out1;
			sstr_in1 << p_input;
			sstr_out1 << p_output;

			vec_in.clear();
			vec_out.clear();
			vec_ret.clear();
			while (sstr_in1 >> tmp)
			{
				vec_in.push_back(tmp);
			}

			while (sstr_out1 >> tmp)
			{
				vec_out.push_back(tmp);
			}

			vec_ret = PlusOne(vec_in);
			b_ret = (vec_ret == vec_out) ? true : false;

			Assert::IsTrue(b_ret);

			//=================================================
			GetPrivateProfileStringA("test18", "Input2", "", p_input, MAX_PATH, INI_PATH_18);
			GetPrivateProfileStringA("test18", "Output2", "", p_output, MAX_PATH, INI_PATH_18);

			stringstream sstr_in2;
			stringstream sstr_out2;
			sstr_in2 << p_input;
			sstr_out2 << p_output;

			vec_in.clear();
			vec_out.clear();
			vec_ret.clear();
			while (sstr_in2 >> tmp)
			{
				vec_in.push_back(tmp);
			}

			while (sstr_out2 >> tmp)
			{
				vec_out.push_back(tmp);
			}

			vec_ret = PlusOne(vec_in);
			b_ret = (vec_ret == vec_out) ? true : false;

			Assert::IsTrue(b_ret);
		}


		TEST_METHOD(Test19)
		{
			// TODO:  在此输入测试代码
			int i_in = 0;
			int i_out = 0;

			i_in = GetPrivateProfileIntA("test19", "Input", 0, INI_PATH_19);
			i_out = GetPrivateProfileIntA("test19", "Output", 0, INI_PATH_19);

			Assert::AreEqual(i_out, MySqrt(i_in));

			i_in = GetPrivateProfileIntA("test19", "Input1", 0, INI_PATH_19);
			i_out = GetPrivateProfileIntA("test19", "Output1", 0, INI_PATH_19);

			Assert::AreEqual(i_out, MySqrt(i_in));
		}


		TEST_METHOD(Test20)
		{
			// TODO:  在此输入测试代码
			LPSTR str_in = new char[MAX_PATH];
			LPSTR str_out = new char[MAX_PATH];

			GetPrivateProfileStringA("test20", "Input", "", str_in, MAX_PATH, INI_PATH_20);
			GetPrivateProfileStringA("test20", "Output", "", str_out, MAX_PATH, INI_PATH_20);

			stringstream sstr_in(str_in);
			stringstream sstr_out(str_out);

			vector<int> vec_in;
			vector<int> vec_out;
			int tmp = 0;

			while (sstr_in >> tmp)
			{
				vec_in.push_back(tmp);
			}

			while (sstr_out >> tmp)
			{
				vec_out.push_back(tmp);
			}

			MoveZeroes(vec_in);

			bool b_result;

			if (vec_in == vec_out)
				b_result = true;

			Assert::IsTrue(b_result);

			vec_in.clear();
			vec_out.clear();

			MoveZeroes(vec_in);

			if (vec_in == vec_out)
				b_result = true;
			else
				b_result = false;

			Assert::IsTrue(b_result);
		}


		TEST_METHOD(Test21)
		{
			// TODO:  在此输入测试代码
			int i_in = 0;
			int i_out = 0;


			i_in = GetPrivateProfileIntA("test21", "Input", 0, INI_PATH_21);
			i_out = GetPrivateProfileIntA("test21", "Output", 0, INI_PATH_21);

			Assert::AreEqual(i_out, Reverse(i_in));

			i_in = GetPrivateProfileIntA("test21", "Input2", 0, INI_PATH_21);
			i_out = GetPrivateProfileIntA("test21", "Output2", 0, INI_PATH_21);

			Assert::AreEqual(i_out, Reverse(i_in));


			i_in = GetPrivateProfileIntA("test21", "Input3", 0, INI_PATH_21);
			i_out = GetPrivateProfileIntA("test21", "Output3", 0, INI_PATH_21);

			Assert::AreEqual(i_out, Reverse(i_in));
		}



		TEST_METHOD(Test22)
		{
			// TODO:  在此输入测试代码
			LPSTR chp_in = new char[MAX_PATH];
			int i_key = 0;
			LPSTR chp_out = new char[MAX_PATH];

			GetPrivateProfileStringA("test22", "Input", "", chp_in, MAX_PATH, INI_PATH_22);
			GetPrivateProfileStringA("test22", "Output", "", chp_out, MAX_PATH, INI_PATH_22);
			i_key = GetPrivateProfileIntA("test22", "key", 0, INI_PATH_22);

			stringstream sstr_in;
			stringstream sstr_out;

			sstr_in << chp_in;
			sstr_out << chp_out;

			vector<int> vec_in;
			vector<int> vec_out;
			int tmp = 0;

			while (sstr_in >> tmp)
			{
				vec_in.push_back(tmp);
			}

			while (sstr_out >> tmp)
			{
				vec_out.push_back(tmp);
			}

			bool result;

			Rotate(vec_in, i_key);

			result = (vec_in == vec_out) ? true : false;

			Assert::IsTrue(result);
		}


		TEST_METHOD(Test23)
		{
			// TODO:  在此输入测试代码

			LPSTR chp_in = new char[MAX_PATH];
			LPSTR chp_out = new char[MAX_PATH];
			stringstream sstr_out;
			string str;
			bool b_result;
			vector<string> vstr_out;


			GetPrivateProfileStringA("test23", "Input", "", chp_in, MAX_PATH, INI_PATH_23);
			GetPrivateProfileStringA("test23", "Output", "", chp_out, MAX_PATH, INI_PATH_23);



			sstr_out << chp_out;


			while (sstr_out >> str)
			{
				vstr_out.push_back(str);
			}

			vector<string> vstr_ret = RestoreIpAddresses(chp_in);



			b_result = (vstr_ret == vstr_out) ? true : false;

			Assert::IsTrue(b_result);

			//===========================================================
			GetPrivateProfileStringA("test23", "Input1", "", chp_in, MAX_PATH, INI_PATH_23);
			GetPrivateProfileStringA("test23", "Output1", "", chp_out, MAX_PATH, INI_PATH_23);

			sstr_out << chp_out;


			while (sstr_out >> str)
			{
				vstr_out.push_back(str);
			}

			vstr_ret = RestoreIpAddresses(chp_in);


			set<string> setstr_ret(vstr_ret.begin(), vstr_ret.end());
			set<string> setstr_out(vstr_out.begin(), vstr_out.end());
			b_result = (setstr_out == setstr_out) ? true : false;

			Assert::IsTrue(b_result);
		}

		TEST_METHOD(Test24)
		{
			// TODO:  在此输入测试代码
			char *pIn = new char[MAX_PATH];
			int iOut = 0;

			GetPrivateProfileStringA("test24", "Input", "", pIn, MAX_PATH, INI_PATH_24);
			iOut = GetPrivateProfileIntA("test24", "Output", 0, INI_PATH_24);

			Assert::AreEqual(iOut, LengthOfLongestSubstring(pIn));

			memset(pIn, 0, MAX_PATH);
			GetPrivateProfileStringA("test24", "Input1", "", pIn, MAX_PATH, INI_PATH_24);
			iOut = GetPrivateProfileIntA("test24", "Output1", 0, INI_PATH_24);

			Assert::AreEqual(iOut, LengthOfLongestSubstring(pIn));

			memset(pIn, 0, MAX_PATH);
			GetPrivateProfileStringA("test24", "Input2", "", pIn, MAX_PATH, INI_PATH_24);
			iOut = GetPrivateProfileIntA("test24", "Output2", 0, INI_PATH_24);

			Assert::AreEqual(iOut, LengthOfLongestSubstring(pIn));
		}

		TEST_METHOD(Test25)
		{
			// TODO:  在此输入测试代码
			int i = 0;//辅助数
			int ini_key = 0; //ini文件的k
			int val = 0;
			int j = 0;
			int array[1000];
			bool result = false;

			//获取一共有多少个[章节]数
			int ini_Numbers = GetPrivateProfileIntA("config_test25", "number", 0, INI_PATH_25);

			for (i = 1; i <= ini_Numbers; i++)
			{
				result = false;
				char sectionName[15] = { "Test" }, sectionCount[10], ini_arrays[1024], ini_out[1024];
				itoa(i, sectionCount, 10);
				strcat(sectionName, sectionCount);
				ini_key = GetPrivateProfileIntA(sectionName, "k", 0, INI_PATH_25);
				GetPrivateProfileStringA(sectionName, "array", "", ini_arrays, sizeof(ini_arrays), INI_PATH_25);
				char *p_ini_arrays = strtok(ini_arrays, ",");
				while (p_ini_arrays != NULL)
				{
					val = atoi(p_ini_arrays);
					array[j] = val;
					j++;
					p_ini_arrays = strtok(NULL, ",");
				}
				vector<int> nums(array, array + j);
				j = 0;
				struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));  //头结点(不存值)
				head->next = NULL;
				CreateList(head, nums);
				ListNode* head1 = Partition(head, ini_key);
				vector<int> array_act;
				vector<int> array_out;
				head1 = head1->next;
				while (head1 != nullptr)
				{
					array_act.push_back(head1->val);
					head1 = head1->next;
				}
				GetPrivateProfileStringA(sectionName, "output", "", ini_out, sizeof(ini_out), INI_PATH_25);
				char *p_ini_arrays5 = strtok(ini_out, ",");
				while (p_ini_arrays5 != NULL)
				{
					array_out.push_back(atoi(p_ini_arrays5));
					p_ini_arrays5 = strtok(NULL, ",");
				}
				if (array_out == array_act)
					result = true;
				array_act.clear();
				array_out.clear();
				Assert::IsTrue(result);
			}
		}
	};
}