/** a simple logger for FakeEngine by Ethan Groat **/

/* When the program is run from terminal, simply direct output to the desired 
   file stream with >
   for example, run: $ ./myfakeapp > log.txt
*/


#include <stdio.h>
#include "types.h"


/* List of ANSI color codes */
#define FAKELOGGER_NORMAL (0)
#define FAKELOGGER_RED (91)
#define FAKELOGGER_GREEN (92)
#define FAKELOGGER_YELLOW (93)
#define FAKELOGGER_BLUE (94)
#define FAKELOGGER_VIOLET (95)
#define FAKELOGGER_CYAN (96)


namespace FakeEngine
{
    class Logger
    {
      private:
        int default_color = FAKELOGGER_NORMAL;
      public:
        Logger();

        Logger(const char* initialization_message);

        /*! @param default_color
            ANSI color code, predefined with FAKELOGGER_[COLOR] */
        Logger(int default_color);
        Logger(int default_color, const char* initialization_message);
        ~Logger();

            /*! @param color
                ANSI color code, predefined with FAKELOGGER_[COLOR] */
        inline void set_color(int color)
            { default_color = color; }

        inline void print(const char* text) const
            { printf("\033[%dm%s", default_color, text); }
        inline void print(int color, const char* text) const
            { printf("\033[%dm%s", color, text); }
        inline void print(int number) const
            { printf("\033[%dm%d", default_color, number); }
        inline void print(unsigned int number) const
            { printf("\033[%dm%08x", default_color, number); }
        inline void print(float number) const
            { printf("\033[%dm%8.2g", default_color, number); }

        inline void printl() const { print("\n"); }
        template<typename T>
        inline void printl(T something) const { print(something); print("\n"); }
        template<typename T>
        inline void printl(int color, T something) const
            { print(color, something); print("\n"); }

        inline void print_vector(vector_2d vec) const
            {
                print("( ");
                print(vec.x);
                print(", ");
                print(vec.y);
                print(" )\n");
            }
        inline void print_vector(vector_3d vec) const
            {
                print("( ");
                print(vec.x);
                print(", ");
                print(vec.y);
                print(", ");
                print(vec.z);
                print(" )\n");
            }
        inline void print_vector(vector_4d vec) const
            {
                print("( ");
                print(vec.x);
                print(", ");
                print(vec.y);
                print(", ");
                print(vec.z);
                print(", ");
                print(vec.q);
                print(" )\n");
            }

        void print_array(vector_2d* content, int rows) const;
        void print_array(vector_3d* content, int rows) const;
        void print_array(vector_4d* content, int rows) const;
    };
}
