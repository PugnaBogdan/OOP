#include "Tests.h"
#include <assert.h>

void testFile()
{
	Repository repositoryTest{};

	repositoryTest.setFIle("sadasdas.text");
	repositoryTest.readFromFile();

	repositoryTest.setFIle("fileTest.txt");
	repositoryTest.readFromFile();

	Data data{ "string", "string", 12.3, 123.54, "string" }; // 12.3 and 123.54 are double
	repositoryTest.addData(data);
	assert(repositoryTest.getsize() == 1);

	Repository repositoryTest2{};
	repositoryTest2.setFIle("fileTest.txt");
	repositoryTest2.readFromFile();

	assert(repositoryTest2.getsize() == 1);
	repositoryTest.deleteData("string");
}

void testServiceRepo()
{

	Repository repositoryTest{};
	RepositoryMyFile* myListTest{};
	Service servicesTest{ repositoryTest, myListTest };

	servicesTest.setFileService("fileTesaSst.txt");
	servicesTest.readFileService();

	servicesTest.setFileService("fileTest.txt");
	servicesTest.readFileService();

	Data data{ "string", "string", 12.3, 123.54, "string" };

	servicesTest.addDataToRepository("string3", "string3", 3.3, 3.3, "string3"); // 3.3 is a double
	servicesTest.deleteDatatoRepository("string3");
	assert(servicesTest.getthis() == 0);

	servicesTest.addDataToRepository("string", "string", 12.3, 123.54, "string");
	assert(servicesTest.getthis() == 1);

	for (auto itterator : servicesTest.getALL())
	{
		assert(itterator.getId() == "string");
		assert(itterator.getImageClarityLevel() == 12.3);
		assert(itterator.getMeasurement() == "string");
		assert(itterator.getQuantity() == 123.54);
		assert(itterator.getPhotograph() == "string");
	}

	servicesTest.updateDataToRepository("string", "string2", 12222.3, 1222223.54, "string2"); // parameter 2 and 3 are double
	assert(servicesTest.getthis() == 1);

	servicesTest.deleteDatatoRepository("string2");
	assert(servicesTest.getthis() == 1);

	servicesTest.deleteDatatoRepository("string");
	assert(servicesTest.getthis() == 0);

}

void testRepositoryMyFile()
{
	Repository repositoryTest{};
	RepositoryMyFile* myListTest{};
	Service servicesTest{ repositoryTest, myListTest };

	servicesTest.addDataToRepository("string", "string", 12.3, 123.54, "string"); // parameter 2 and 3 are double
	servicesTest.saveService("string");
	assert(servicesTest.getthisMyList() == 1);

	for (auto itterator : servicesTest.getALLmyList())
	{
		assert(itterator.getId() == "string");
		assert(itterator.getImageClarityLevel() == 12.3);
		assert(itterator.getMeasurement() == "string");
		assert(itterator.getQuantity() == 123.54);
		assert(itterator.getPhotograph() == "string");
	}

}

void testIsolated()
{
	IsolatedRepository repositoryTester{};
	Data data{ "string", "string", 12.3, 123.54, "string" };
	try
	{
		repositoryTester.updateData(data);
	}
	catch (exception& exception)
	{
		assert(exception.what() == "isolatedTestNotCought");
	}
	Data data2{ "isolatedId", "string", 12.3, 123.54, "string" };
	try
	{
		repositoryTester.updateData(data2);
	}
	catch (exception& exception)
	{
		assert(exception.what() == "isolatedTestCought");
	}
}

void runTests()
{
	testFile();
	testServiceRepo();
	testRepositoryMyFile();
}
