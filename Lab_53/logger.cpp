// Singleton logger: every report() is appended to log.txt.
// After ONE run log.txt must contain 27 lines:
//   begin
//   then five times:  11 12 21 22 23  (one per line)
//   end
// A SECOND run must append another 27 lines (the file is never truncated).
// There must be exactly one Logger object in the whole program.

#include <iostream>
#include <string>

class Logger {
   public:
    static Logger& instance() {
        Logger instance;
        return instance;
    }

    void report(const std::string& message) {
        fout << message << std::endl;
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

   private:
    std::ofstream fout;

    Logger() {
        fout.open("log.txt", std::fstream::out);
    }

    ~Logger() {
        fout.close();
    }
};

void run1() {
    Logger::instance().report("11");
    Logger::instance().report("12");
}

void run2() {
    Logger::instance().report("21");
    Logger::instance().report("22");
    Logger::instance().report("23");
}

int main() {
    Logger::instance().report("begin");

    run1();
    run2();
    run1();
    run2();
    run1();
    run2();
    run1();
    run2();
    run1();
    run2();

    
    Logger logger;
    logger.report("end");

    return 0;
}
