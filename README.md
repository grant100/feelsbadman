# feelsbadman
Simple malware program that:
  - Clones/copies itself
  - Removes itself
  - Contacts a C2 server: Downloads and runs new executable, and exfiltrates running processes.
  - Sets windows registry RUN key for persistence.
  - Checks for running debuggers. 
  - Starts a key logger thread: Key logger xors captured keys and exfils to C2 server.
  
