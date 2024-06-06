#include "pch.h"
#include "CppUnitTest.h"
#include "..\Apartment.cpp"
#include "..\Samplings.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	private:
		//�������� ����������� �������� ������ Apartment
		Apartment app1{ /*�����:*/"test1",/*����:*/ 2,/*���-�� ������:*/ 2,/*�������*/ 10};
		Apartment app2{ /*�����:*/"test2",/*����:*/ 2,/*���-�� ������:*/ 3,/*�������*/ 11 };
		Apartment app3{ /*�����:*/"test3",/*����:*/ 3,/*���-�� ������:*/ 4,/*�������*/ 12 };
		Apartment app4{ /*�����:*/"test4",/*����:*/ 3,/*���-�� ������:*/ 5,/*�������*/ 13 };
		Apartment app5{ /*�����:*/"test5",/*����:*/ 3,/*���-�� ������:*/ 6,/*�������*/ 14 };
	public:
		//�������� ������� �� ���-�� ������
		TEST_METHOD(TestMethod1)
		{
			//�������� ������ ����������� �������
			std::vector<Apartment> apartments;
			//���������� ������� � ����� �������
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			//������� ������� � 2�� ���������, �.� �������� ������ app1
			std::vector<Apartment> sortedApartments = SamplingApartmentsByRoomCount(apartments,/*���� �������� ������ �.� ���-�� �������*/ 2);
			Assert::IsTrue(sortedApartments.size() == 1);//�������� �� �� ��� � ������� 1 ���������� ��������
			Assert::IsTrue(sortedApartments.at(0) == app1);//�������� ��� ���� ������ app1 �.� �������� �� ������: test1
			//������� ������� � 3�� ���������, �.� �������� ������ app2
			 sortedApartments = SamplingApartmentsByRoomCount(apartments,/*���� �������� ������ �.� ���-�� �������*/ 3);
			 Assert::IsTrue(sortedApartments.size() == 1);//�������� �� �� ��� � ������� 1 ���������� ��������
			Assert::IsTrue(sortedApartments.at(0) == app2);//�������� ��� ���� ������ app2 �.� �������� �� ������: test2
			//������� ������� � 4�� ���������, �.� �������� ������ app3
			 sortedApartments = SamplingApartmentsByRoomCount(apartments,/*���� �������� ������ �.� ���-�� �������*/ 4);
			 Assert::IsTrue(sortedApartments.size() == 1);//�������� �� �� ��� � ������� 1 ���������� ��������
			Assert::IsTrue(sortedApartments.at(0) == app3);//�������� ��� ���� ������ app3 �.� �������� �� ������: test3
			//������� ������� � 5� ���������, �.� �������� ������ app4
			sortedApartments = SamplingApartmentsByRoomCount(apartments,/*���� �������� ������ �.� ���-�� �������*/ 5);
			Assert::IsTrue(sortedApartments.size() == 1);//�������� �� �� ��� � ������� 1 ���������� ��������
			Assert::IsTrue(sortedApartments.at(0) == app4);//�������� ��� ���� ������ app4 �.� �������� �� ������: test4
			//������� ������� � 6� ���������, �.� �������� ������ app5
			sortedApartments = SamplingApartmentsByRoomCount(apartments,/*���� �������� ������ �.� ���-�� �������*/ 8);
			Assert::IsTrue(sortedApartments.empty());//�������� �� �� ��� � ������� ��� ���������� ��������
		}
		//�������� ������� �� ���-�� ������ � ��������� � ����������� �����
		TEST_METHOD(TestMethod2)
		{
			//�������� ������ ����������� �������
			std::vector<Apartment> apartments;
			//���������� ������� � ����� �������
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			//������� ������� � 3�� ��������� ����������� � ���������� ������ �� 2 �� 3, �.� �������� ������ app2
			std::vector<Apartment> sortedApartments = SamplingApartmentsByRoomCountAndFloorGap(apartments,/*���-�� ������*/3,/*�������� ������*/std::tuple<int, int>(2, 3));
			Assert::IsTrue(sortedApartments.size() == 1);//�������� �� �� ��� � ������� 1 ���������� ��������
			Assert::IsTrue(sortedApartments.at(0) == app2);//�������� ��� ���� ������ app2 �.� �������� �� ������: test2
		}
		//�������� ������� �� ���-�� ������ � ��������� � ����������� �����
		TEST_METHOD(TestMethod3)
		{
			//�������� ������ ����������� �������
			std::vector<Apartment> apartments;
			//���������� ������� � ����� �������
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			//������� ������� � 4�� ��������� ����������� � ���������� ������ � 4 �� 3, �.� ������� ������� �� ��������
			std::vector<Apartment> sortedApartments = SamplingApartmentsByRoomCountAndFloorGap(apartments, /*���-�� ������*/4, /*�������� ������*/std::tuple<int, int>(4, 5));
			Assert::IsTrue(sortedApartments.empty());//�������� �� �� ��� � ������� ��� ��������
		}
		//�������� ������� �� �������
		TEST_METHOD(TestMethod4)
		{
			//�������� ������ ����������� �������
			std::vector<Apartment> apartments;
			//���������� ������� � ����� �������
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			//������� ������� � �������� ������ 12, �.� �������� ������ app4,app5
			std::vector<Apartment> sortedApartments = SamplingApartmentsByArea(apartments, /*�������*/12);
			Assert::IsTrue(sortedApartments.size() == 2);//�������� �� �� ��� � ������� 2 ���������� ��������
			Assert::IsTrue(sortedApartments.at(0) == app4);//�������� ��� ���� ������ app4 �.� �������� �� ������: test4
			Assert::IsTrue(sortedApartments.at(1) == app5);//�������� ��� ���� ������ app5 �.� �������� �� ������: test5
		}
		TEST_METHOD(TestMethod5)
		{
			//�������� ������ ����������� �������
			std::vector<Apartment> apartments;
			//���������� ������� � ����� �������
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			//������� ������� � �������� ������ 20, �.� �.� ������� ������� �� ��������
			std::vector<Apartment> sortedApartments = SamplingApartmentsByArea(apartments,/*�������*/ 20);
			Assert::IsTrue(sortedApartments.empty());//�������� �� �� ��� � ������� ��� ��������
		}
	};
}
