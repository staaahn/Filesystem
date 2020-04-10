// Driver File

createFile() {
  LBA_write( stuff) 
}

readFile() {
 LBA_read 
}

listDir() {
  LBA_read()
}

createDir() {
  LBA_write()
}

#include "CreateFile.h"
#include "ListDir.h"
#include "CreateDir.h"


main () {
  startpartition (stuff) // beer
  while(true) {
    //menu
    1. create a dir
      createDir(dir name);
    2. list dir
      listDir();
    3. create a file
    4. rm a file
            enter the filename
            removed file (filename)
    10. enter q to quit
  }
    
  closepartition (stuff) // beer
}
