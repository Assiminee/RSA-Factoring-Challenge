#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	Py_Initialize();

    // Execute the Python code
    PyRun_SimpleString("import math\n"
                      "print(f'{math.sqrt(1718944270642558716715)}')");

    // Finalize the Python interpreter
    Py_Finalize();
    return (0);
}
