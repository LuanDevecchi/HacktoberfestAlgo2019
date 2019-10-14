# Merge sort implementation using Database
import mysql.connector
conn = mysql.connector.connect(     host='localhost', # your host name
                                    database='lab', # Your database name
                                    user='root', # Username to access DB
                                    password='') # Password of user
crsr = conn.cursor()
def get_array():
    arr = """SELECT class_rn FROM stud """   # SELECT comlumn_name FROM table_name
    crsr.execute(arr)
    rows = crsr.fetchall()
    array = []
    for row in rows:
        array.append((row[0]))
    return array

def merge_sort(alist):
    if len(alist)>1:
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]

        merge_sort(lefthalf)
        merge_sort(righthalf)

        i=0
        j=0
        k=0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] <= righthalf[j]:
                alist[k]=lefthalf[i]
                i=i+1
            else:
                alist[k]=righthalf[j]
                j=j+1
            k=k+1

        while i < len(lefthalf):
            alist[k]=lefthalf[i]
            i=i+1
            k=k+1

        while j < len(righthalf):
            alist[k]=righthalf[j]
            j=j+1
            k=k+1
    return(alist)

arr = merge_sort(get_array())
print(arr)

crsr.close()
conn.close()
