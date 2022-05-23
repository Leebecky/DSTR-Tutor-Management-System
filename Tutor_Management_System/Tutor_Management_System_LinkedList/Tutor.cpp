#include<string>
#include<iostream>
#include<ctime>

#include "Tutor.h"

using namespace std;
Tutor::Tutor() {

}

Tutor::Tutor(int tutorId, string name, tm dateJoined, double hourlyPayRate, string phone, string address, int centerCode, string centerName, int subjectCode, string subjectName, int rating)  //Base Constructor
{
	this->tutorId = tutorId;
	this->name = name;
	this->dateJoined = dateJoined;
	this->hourlyPayRate = hourlyPayRate;
	this->phone = phone;
	this->address = address;
	this->centerCode = centerCode;
	this->centerName = centerName;
	this->subjectCode = subjectCode;
	this->subjectName = subjectName;
	this->rating = rating;

}


//Display the main menu
void mainMenu()
{
	cout << "Main Menu:" << endl;
	cout << "1. Display All Tutor" << endl;
	cout << "2. Add New Tutor" << endl;
	cout << "3. Search by Tutor ID" << endl;
	cout << "4. Search by Tutor Rating" << endl;
	cout << "0. Exit" << endl;
	cout << "Please enter the desired menu option: ";
}


//Display the menu when viewing the tutor list
void tutorListMenu()
{
	cout << "Tutor List:" << endl;
	cout << "1. View Tutor" << endl;
	cout << "2. Sort by Tutor ID" << endl;
	cout << "3. Sort by Tutor Hourly Pay" << endl;
	cout << "4. Sort by Tutor Rating" << endl;
	cout << "5. Delete Tutor" << endl;
	cout << "6. Next page" << endl;
	cout << "7. Previous page" << endl;
	cout << "0. Back to Main Menu" << endl;
	cout << "Please enter the desired menu option: ";
}


//Redirects the user based on given input
void tutorMenuControl(int* input, Tutor** head, Tutor** tail, int *tutorListCount, int* currentPage)
{
	switch (*input)
	{
	case 1:
		cout << "Tutor Details Here" << endl;
		break;
	case 2:
		cout << "Sort by Tutor Id" << endl;
		sortByTutorId(head, tail, tutorListCount);
		break;
	case 3:
		cout << "Sort by Pay" << endl;
		sortByHourlyPay(head, tail);
		break;
	case 4:
		cout << "Sort by Rating" << endl;
		sortByRating(head, tail);
		break;
	case 5:
		cout << "Enter tutor id: " << endl;
		break;
	case 6:
		*currentPage = *currentPage + 1;
		break;
	case 7:		
		*currentPage = *currentPage - 1;
		break;
	default:
		break;
	}

}


void generateData(Tutor **head, Tutor** tail, int* tutorListCount) {
	Tutor *data1 = new Tutor(1, "Zainul bin Zabidin", tm(), 75.00, "011-1234567", "19, Jalan A12, Taman Asia, 68000 Ampang, Selangor", 1, "Pusat Asia Jaya", 1, "Bahasa Melayu", 3);
	Tutor *data2 = new Tutor(2, "Alina Chan Mei Yi", tm(), 80.00, "016-5423412", "22, Jalan B1, Taman Bestari, 68000 Ampang, Selangor", 1, "Pusat Asia Jaya", 5, "Biology", 5);
	Tutor *data3 = new Tutor(3, "Dhanyasree a/p Muthusamy", tm(), 60.00, "017-3415136", "A12, Block-C, Oakleaf Condominium, 51000 Kuala Lumpur", 1, "Pusat Asia Jaya", 2, "English", 1);
	Tutor *data4 = new Tutor(4, "Cassim Tan", tm(), 75.00, "016-1237568", "97, Jalan ST1, Taman Stadhuys, 68000 Ampang, Selangor", 1, "Pusat Asia Jaya", 3, "Sejarah", 3);
	Tutor *data5 = new Tutor(5, "Nurul Syafiqah", tm(), 65.00, "011-845656455", "65, Jalan M1, Taman Mega, 68000 Ampang, Selangor", 1, "Pusat Asia Jaya", 4, "Geografi", 2);
	Tutor *data6 = new Tutor(6, "Maggie Simon", tm(), 50.00, "011-57457823", "11, Jalan M1, Taman Mega, 68000 Ampang, Selangor", 2, "Pusat Megah Jaya", 9, "Mathematics", 2);
	Tutor *data7 = new Tutor(7, "Ai Ling Tan", tm(), 75.00, "015-123434656", "65, Jalan M1, Taman Mega, 68000 Ampang, Selangor", 2, "Pusat Megah Jaya", 10, "Additional Mathematics", 5);
	Tutor *data8 = new Tutor(8, "Diviya Nathan", tm(), 50.00, "011-958567555", "561, Jalan Sinar 1, Taman Sinar, 68000 Ampang, Selangor", 2, "Pusat Megah Jaya", 2, "English", 1);
	Tutor *data9 = new Tutor(9, "Daryl Arul", tm(), 75.00, "016-98653544", "17, Jalan M2, Taman Mega, 68000 Ampang, Selangor", 2, "Pusat Megah Jaya", 8, "Chemistry", 2);
	Tutor *data10 = new Tutor(10, "Suhaimi bin Suhakam", tm(), 55.00, "011-845656455", "65, Jalan M1, Taman Mega, 68000 Ampang, Selangor", 2, "Pusat Megah Jaya", 7, "Physics", 5);
	Tutor *data11 = new Tutor(11, "Paula Maruice", tm(), 60.00, "016-45452777", "67, Jalan Bkt Utama, Taman Bukit, 68000 Ampang, Selangor", 3, "Pusat Suru Jaya", 4, "Geografi", 4);
	Tutor *data12 = new Tutor(12, "Chan Mei Kong", tm(), 55.00, "012-24562453", "7-A-1, Emerald Condominium, 68000 Ampang, Selangor", 3, "Pusat Suru Jaya", 5, "Biology", 4);
	Tutor *data13 = new Tutor(13, "Cassi Hassan", tm(), 80.00, "016-756455554", "97, Jalan Bendara, Taman Antarabangsa, 68000 Ampang, Selangor", 3, "Pusat Suru Jaya", 8, "Chemistry", 5);
	Tutor *data14 = new Tutor(14, "Nurul Aslina", tm(), 50.00, "011-673334s76", "65, Jalan M3, Taman Mega, 68000 Ampang, Selangor", 3, "Pusat Suru Jaya", 1, "Bahasa Melayu", 3);
	Tutor *data15 = new Tutor(15, "Li Su Yan", tm(), 78.50, "018-88345346", "99, Jalan B1, Taman Bestari, 68000 Ampang, Selangor", 3, "Pusat Suru Jaya", 10, "Additioanl Mathematics", 4);

	data1->next = data2;
	data1->prev = NULL;

	data2->next = data3;
	data2->prev = data1;

	data3->next = data4;
	data3->prev = data2;

	data4->next = data5;
	data4->prev = data3;

	data5->next = data6;
	data5->prev = data4;

	data6->next = data7;
	data6->prev = data5;

	data7->next = data8;
	data7->prev = data6;

	data8->next = data9;
	data8->prev = data7;

	data9->next = data10;
	data9->prev = data8;

	data10->next = data11;
	data10->prev = data9;

	data11->next = data12;
	data11->prev = data10;

	data12->next = data13;
	data12->prev = data11;

	data13->next = data14;
	data13->prev = data12;

	data14->next = data15;
	data14->prev = data13;

	data15->next = NULL;
	data15->prev = data14;

	(*head) = data1;
	(*tail) = data15;
	*tutorListCount = 15;
}

void displayTutorList(Tutor* head, int size, int* currentPage) {
	
	int currentPosition, maxPosition, maxPage;
	if (size % 5 != 0) {
		maxPage = (size / 5) + 1;
	}
	else {
		maxPage = size / 5;
	}

	if (*currentPage == 0) {
		*currentPage = maxPage;
	}
	else if (*currentPage > maxPage) {
		*currentPage = 1;
	}

	if (*currentPage == maxPage) {
		maxPosition = 5 * (size / 5) + (size % 5);
	}
	else {
		maxPosition = 5 * *currentPage;
	}

	currentPosition = (*currentPage - 1) * 5;

	cout << " Id" << "\t| ";
	cout << "Tutor Name" << "\t| ";
	cout << "Pay Rate" << "\t| ";
	cout << "Center Code" << "\t| ";
	cout << "Center Name" << "\t| ";
	cout << "Rating" << endl;

	Tutor *temp = head;
	for (int i = 0; i < maxPosition; i++)
	{
		if (i >= currentPosition) {
			cout << " #" << (temp)->tutorId << "\t| ";
			cout << (temp)->name << "\t\t| ";
			cout << (temp)->hourlyPayRate << "\t\t| ";
			cout << (temp)->centerCode << "\t\t| ";
			cout << (temp)->centerName << "\t\t| ";
			cout << (temp)->rating << endl;
		}

		temp = temp->next;

	}

	cout << "\nPage  " << *currentPage << " / " << maxPage << endl;
}


//Bubble Sort - Sort tutor list by Tutor Id
void sortByTutorId(Tutor **head, Tutor **tail, int *count) {
	Tutor **temp = head;
	bool swapped = false;
	cout << *count << endl;
	for (int i = 0; i < *count; i++) {
		temp = head;
		swapped = false;

		for (int j = 0; j < *count - i - 1; j++) {
			Tutor* node1 = *temp;
			Tutor* node2 = node1->next;

			// Comparing values for tutor id
			if (node1->tutorId > node2->tutorId) {

				//Swap nodes
				*temp = swapNode(node1, node2);
				swapped = true;
			}

			temp = &(*temp)->next;

		}

		//Break the outer loop if no swap happens
		if (!swapped) {
			break;
		}
	}
	*tail = getTail(*temp);
}

//Reference: https://www.geeksforgeeks.org/bubble-sort-for-linked-list-by-swapping-nodes/
// Swap the nodes in the linked list
Tutor* swapNode(Tutor *node1, Tutor *node2) {
	Tutor *nextNode = node2->next;
	Tutor *prevNode = node1->prev;

	node2->next = node1;
	node2->prev = prevNode;
	node1->next = nextNode;
	node1->prev = node2;

	if (nextNode != NULL) {
		nextNode->prev = node1;
	}

	if (prevNode != NULL) {
		prevNode->next = node2;
	}
	return node2;
}

//Reference: https://www.geeksforgeeks.org/quicksort-for-linked-list/

// Returns the last node of the list
Tutor *getTail(Tutor *cur)
{
	while (cur != NULL && cur->next != NULL) {
		cur = cur->next;
	}

	return cur;
}

// Partitions the list taking the last element as the pivot
Tutor *partition(Tutor *head, Tutor *tail, Tutor **newHead, Tutor **newEnd)
{
	Tutor *pivot = tail;
	Tutor  *current = head, *listEnd = pivot;
	Tutor *prev = NULL;

	// During partition, both the head and end of the list might change
	// which is updated in the newHead and newEnd variables
	while (current != pivot)
	{
		if (current->hourlyPayRate < pivot->hourlyPayRate)
		{
			// First node that has a value less than the pivot - becomes
			// the new head
			if ((*newHead) == NULL) {
				(*newHead) = current;
			}


			prev = current;
			current = current->next;
		}
		else // If current Tutor is greater than pivot
		{
			// Move current Tutor to next of listEnd, and change listEnd

			if (prev) {
				prev->next = current->next;
			}

			////if (current->prev != NULL) {
			////	(current->prev)->next = current->next;
			//}

			Tutor *tmp = current->next;
			tmp->prev = current->prev;
			current->next = NULL;
			current->prev = listEnd;
			listEnd->next = current;
			listEnd = current;
			current = tmp;

			//Tutor *tmp = current->next;
			//current->next = NULL;
			//listEnd->next = current;
			//listEnd = current;
			//current = tmp;
		}
	}

	// If the pivot data is the smallest element in the current list,
	// pivot becomes the head
	if ((*newHead) == NULL) {
		(*newHead) = pivot;
	}


	// Update newEnd to the current last node
	(*newEnd) = listEnd;

	// Return the pivot Tutor
	return pivot;
}


//here the sorting happens exclusive of the end node
Tutor *quickSortRecur(Tutor *head, Tutor *tail)
{
	// base condition
	if (!head || head == tail) {
		return head;
	}

	Tutor *newHead = NULL, *newEnd = NULL;

	// Partition the list, newHead and newEnd will be updated
	// by the partition function
	Tutor *pivot = partition(head, tail, &newHead, &newEnd);

	// If pivot is the smallest element - no need to recur for
	// the left part.
	if (newHead != pivot)
	{
		// Set the Tutor before the pivot Tutor as NULL
		Tutor *tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;

		// Recur for the list before pivot
		newHead = quickSortRecur(newHead, tmp);

		// Change next of last Tutor of the left half to pivot
		tmp = getTail(newHead);
		tmp->next = pivot;
	}

	// Recur for the list after the pivot element
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;
}

void sortByHourlyPay(Tutor** head, Tutor **tail) {
	(*head) = quickSortRecur((*head), (*tail));
	(*tail) = getTail(*head);

}

void sortByRating(Tutor **head, Tutor **tail) {
	MergeSort(head);
	*tail = getTail(*head);
}

Tutor* Merge(Tutor* h1, Tutor* h2)
{
	Tutor *t1 = new Tutor();
	Tutor *t2 = new Tutor();
	Tutor *temp = new Tutor();

	// Return if the first list is empty.
	if (h1 == NULL)
		return h2;

	// Return if the Second list is empty.
	if (h2 == NULL)
		return h1;

	t1 = h1;

	// A loop to traverse the second list, to merge the Tutors to h1 in sorted way.
	while (h2 != NULL)
	{
		// Taking head Tutor of second list as t2.
		t2 = h2;

		// Shifting second list head to the next.
		h2 = h2->next;
		t2->prev = NULL;
		t2->next = NULL;

		// If the data value is lesser than the head of first list add that Tutor at the beginning.
		if (h1->rating > t2->rating)
		{
			h1->prev = t2;
			t2->next = h1;
			h1 = t2;
			t1 = h1;
			continue;
		}

		// Traverse the first list.
	flag:
		if (t1->next == NULL)
		{
			t1->next = t2;
			t2->prev = t1;
			t1 = t1->next;
		}
		// Traverse first list until t2->data more than Tutor's data.
		else if ((t1->next)->rating <= t2->rating)
		{
			t1 = t1->next;
			goto flag;
		}
		else
		{
			// Insert the Tutor as t2->data is lesser than the next Tutor.
			temp = t1->next;
			t1->next = t2;
			t2->next = temp;
			t2->prev = t1;
			temp->prev = t2;
		}
	}

	// Return the head of new sorted list.
	return h1;
}


// Merge Sort
void MergeSort(Tutor **head)
{
	Tutor *first = new Tutor;
	Tutor *second = new Tutor;
	Tutor *temp = new Tutor;
	first = *head;
	temp = *head;

	// Return if list have less than two nodes.
	if (first == NULL || first->next == NULL)
	{
		return;
	}
	else
	{
		// Break the list into two half as first and second as head of list.
		while (first->next != NULL)
		{
			first = first->next;
			if (first->next != NULL)
			{
				temp = temp->next;
				first = first->next;
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *head;
	}

	// MergeSort both lists
	MergeSort(&first);
	MergeSort(&second);

	// Merge the both lists into a single list.      
	*head = Merge(first, second);
}