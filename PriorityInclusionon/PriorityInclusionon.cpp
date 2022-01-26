#include "priority_inclusion.h"


int main()
{
	setlocale(0, "UKR");

	ProiritInlusiononyQueue q(25);

	q.Enqueue("преподаватель, Александр", 1);
	q.Enqueue("директор филиала, Диана", 4);
	q.Enqueue("менеджер учебного процесса, Екатерина", 2);
	q.Enqueue("заведующая кафедрой, Кристина", 3);
	q.Enqueue("генеральный директор, Дмитрий", 5);
	q.Enqueue("преподаватель, Александр1", 1);
	q.Enqueue("преподаватель, Александр2", 1);
	q.Enqueue("заведующая кафедрой, Кристина1", 3);
	q.Print();



	q.Dequeue();
	q.Print();

	q.Dequeue();
	q.Print();

	q.Dequeue();
	q.Print();

	q.Dequeue();
	q.Print();
}
