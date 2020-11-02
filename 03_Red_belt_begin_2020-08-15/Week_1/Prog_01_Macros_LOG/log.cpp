#include <sstream>
#include <string>
using namespace std;

class Logger {
public:
    explicit Logger(ostream& output_stream) : os(output_stream) {
    }

    void SetLogLine(bool value) { log_line = value; }
    void SetLogFile(bool value) { log_file= value;  }
    void Log(const string& message) {
        os << message;
    };
    bool GetLogLine() {return log_line;}
    bool GetLogFile() {return log_file;}

private:
    ostream& os;
    bool log_line = false;
    bool log_file = false;
};

#define LOG(logger, message)       {                      \
ostringstream to_message;                                 \
if (!logger.GetLogLine() && !logger.GetLogFile()) {       \
to_message << message << "\n" ;                           \
                      }                                   \
   else                                                   \
if (!logger.GetLogLine() && logger.GetLogFile()) {        \
    to_message << __FILE__ << " " << message << "\n";     \
                }                                         \
   else                                                   \
  if (logger.GetLogLine() && logger.GetLogFile()) {       \
    to_message << __FILE__ << ":"                         \
    << __LINE__ << " " << message << "\n";                \
                }                                         \
 else if (logger.GetLogLine() && !logger.GetLogFile()) {  \
    to_message <<"Line " <<  __LINE__                     \
    << " " << message << "\n";                            \
      }                                                   \
       logger.Log(to_message.str());    }