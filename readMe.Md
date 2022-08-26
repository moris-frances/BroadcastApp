Compilation: 
    sender: make s 
    receiver: make r

Running:
    ./sender has to run first
    while ./sender is running, run ./receiver in another window

Result:
    write single characters in ./sender stdin and on every fifth {Return}, the receiver will print the sent characters in a string

Exit: 
    Exit by killing the process