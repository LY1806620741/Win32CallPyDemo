import os
print("error")
os.system("echo|set /p=\"error ... \"  >> Exec.log")
raise -1
os.system("echo done  >> Exec.log")