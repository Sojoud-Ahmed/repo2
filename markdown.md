##commands 
  ## File System Operation:
   1.ls: List files and directories.
   2.pwd: Print the current working directory.
   3.cd: Change directory.
   4.mkdir: Create a new directory.
   5.cp: Copy files and directories.
   6.mv: Move or rename files and directories.
   7.rm: Remove files and directories.
   8.find: Search for files and directories.
  ##File Manipulation:
   1.touch:create empty files and update the modification and access time of existing files.
   2.cat:concatenate and display file content.
##Tools:
 ##Networking:
  1.ssh: establish a secure shell connection between between a local and remote computer.
  2.netcat:Network statistics and connections monitoring.
 ##Text Editor:
  1.nano:simple and beginner-friendly text editor.
           ---------------------------------------------------------------
vboxuser@ubuntu:~$ ls
Desktop  Documents  Downloads  Music  Pictures  Public  snap  Templates  Videos
vboxuser@ubuntu:~$ pwd
/home/vboxuser
vboxuser@ubuntu:~$ ls -l
total 36
drwxr-xr-x 2 vboxuser vboxuser 4096 سبت  2 21:28 Desktop
drwxr-xr-x 2 vboxuser vboxuser 4096 سبت  2 21:28 Documents
drwxr-xr-x 2 vboxuser vboxuser 4096 سبت  2 21:28 Downloads
drwxr-xr-x 2 vboxuser vboxuser 4096 سبت  2 21:28 Music
drwxr-xr-x 2 vboxuser vboxuser 4096 سبت  2 21:28 Pictures
drwxr-xr-x 2 vboxuser vboxuser 4096 سبت  2 21:28 Public
drwx------ 5 vboxuser vboxuser 4096 سبت  2 21:53 snap
drwxr-xr-x 2 vboxuser vboxuser 4096 سبت  2 21:28 Templates
drwxr-xr-x 2 vboxuser vboxuser 4096 سبت  2 21:28 Videos
vboxuser@ubuntu:~$ cd
vboxuser@ubuntu:~$ cd Desktop
vboxuser@ubuntu:~/Desktop$ touch file
vboxuser@ubuntu:~/Desktop$ cat >file2

hello
^Z
[1]+  Stopped                 cat > file2
vboxuser@ubuntu:~/Desktop$ cat file2 

hello
vboxuser@ubuntu:~/Desktop$ cat >>file2
hi
^Z
[2]+  Stopped                 cat >> file2
vboxuser@ubuntu:~/Desktop$ cat file2

hello
hi
vboxuser@ubuntu:~/Desktop$ mkdir new folder
vboxuser@ubuntu:~/Desktop$ mkdir file3 file4
vboxuser@ubuntu:~/Desktop$ ls
file  file2  file3  file4  folder  new
vboxuser@ubuntu:~/Desktop$ ls -l
total 20
-rw-rw-r-- 1 vboxuser vboxuser    0 سبت  2 22:02 file
-rw-rw-r-- 1 vboxuser vboxuser   10 سبت  2 22:06 file2
drwxrwxr-x 2 vboxuser vboxuser 4096 سبت  2 22:09 file3
drwxrwxr-x 2 vboxuser vboxuser 4096 سبت  2 22:09 file4
drwxrwxr-x 2 vboxuser vboxuser 4096 سبت  2 22:08 folder
drwxrwxr-x 2 vboxuser vboxuser 4096 سبت  2 22:08 new
vboxuser@ubuntu:~/Desktop$ rm file2
vboxuser@ubuntu:~/Desktop$ ls
file  file3  file4  folder  new


