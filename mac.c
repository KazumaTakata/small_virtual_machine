
#include <stdio.h>
#include <stdbool.h>

bool running = true;
int ip = 0;
int sp = -1;

int stack[256];

typedef enum
{
    PSH,
    ADD,
    POP,
    HLT
} InstructionSet;

const int program[] = {
    PSH,
    5,
    PSH,
    100,
    ADD,
    POP,
    HLT};

int fetch()
{
    return program[ip];
}

void eval(int instr)
{
    switch (instr)
    {
    case HLT:
    {
        running = false;
        printf("done\n");
        break;
    }
    case PSH:
    {
        sp++;
        stack[sp] = program[++ip];
        break;
    }

    case POP:
    {
        int val_popped = stack[sp--];
        printf("popped %d\n", val_popped);
        break;
    }

    case ADD:
    {
        int a = stack[sp--];
        int b = stack[sp--];

        int result = b + a;

        sp++;
        stack[sp] = result;

        break;
    }
    }
}

int main()
{
    while (running)
    {
        eval(fetch());
        ip++;
    }
}
