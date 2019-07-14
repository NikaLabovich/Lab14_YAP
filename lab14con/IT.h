#pragma once
#define ID_MAXSIZE		10			// мксимальное количество символов в идентификаторе
#define TI_MAXSIZE		4096		// максимальное количество строк в таблице идентификаторо
#define TI_INT_DEFAULT	0x00000000	// значение по умолчнию типа integer
#define TI_STR_DEFAULT	0x00		// значение по умолчнию типа string
#define TI_NULLIDX		0xffffffff	// нет элемента таблицы идентификаторов
#define TI_STR_MAXSIZE	255		

namespace IT			// таблица идентификаторов
{
	enum IDDATATYPE { INT = 1, STR = 2 };			//типы данных идентификаторов: integer, string
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, OP = 5 };	//типы идентификаторов: переменная, функция, параметр, литерал

	struct Entry	//строка таблицы идентификаторов
	{
		int			idxfirstLE;			// индекс 1 строки в таблице лексем
		unsigned char	visibility[ID_MAXSIZE];
		unsigned char	id[ID_MAXSIZE];		// идентификатор (автоматически усекается до ID_MAXSIZE)
		IDDATATYPE	iddatatype;			// тип данных
		IDTYPE		idtype;				// тип идентификатора
		union
		{
			int vint;					// значение integer
			struct
			{
				int len;						// количество символов в string
				unsigned char str[TI_STR_MAXSIZE - 1];	// символы string
			} vstr;				// значение string
		} value;		// значение идентификаторов
	};

	struct IdTable				// экземпляр таблицы идентификаторов
	{
		int maxsize;			// емкость таблицы идентификаторов < TI_MAXSIZE
		int size;				// текущий размер таблицы идентификаторов < maxsize
		Entry* table;			// массив строк таблицы идентификаторов
	};

	IdTable Create(				// создать таблицу идентификаторов
		int size				// емкость таблицыидентификаторов < TI_MAXSIZE
	);

	void Add(				// добавить строку в таблицу идентификаторов
		IdTable& idtable,	// экземпляр таблицы идентификаторов
		Entry entry			// строка таблицы идентификаторов
	);

	Entry GetEntry(			// получить строку таблицы идентификаторов
		IdTable& idtable,	// экземпляр таблицы идентификаторов
		int n				// номер получаемой строки 
	);

	int IsId(				// возврат: номер строки (если есть), TI_NULLIDX (если нет)
		IdTable& idtable,	// экземпляр таблицы идентификаторов
		unsigned char id[ID_MAXSIZE]	// идентификатор
	);

	void Delete(IdTable& idtable);	// удалить таблицу лексем (освободить память)
	void showTable(IdTable& idtable);
	void newShowTable(IdTable& idtable);
};