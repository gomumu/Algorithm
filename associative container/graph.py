import matplotlib.pyplot as plt
out_path = 'D:/out'

f = open(out_path+"/map_insert.txt")
read = f.readline()
m_insert_x = map(int, read.strip().split(','))
read = f.read()
m_insert_y = map(int, read.strip().split(','))

f = open(out_path+"/map_find.txt")
read = f.readline()
m_find_x = map(int, read.strip().split(','))
read = f.read()
m_find_y = map(int, read.strip().split(','))

f = open(out_path+"/map_delete.txt")
read = f.readline()
m_delete_x = map(int, read.strip().split(','))
read = f.read()
m_delete_y = map(int, read.strip().split(','))

f = open(out_path+"/unordered_map_insert.txt")
read = f.readline()
um_insert_x = map(int, read.strip().split(','))
read = f.read()
um_insert_y = map(int, read.strip().split(','))

f = open(out_path+"/unordered_map_find.txt")
read = f.readline()
um_find_x = map(int, read.strip().split(','))
read = f.read()
um_find_y = map(int, read.strip().split(','))

f = open(out_path+"/unordered_map_delete.txt")
read = f.readline()
um_delete_x = map(int, read.strip().split(','))
read = f.read()
um_delete_y = map(int, read.strip().split(','))

# m_insert_x ,m_insert_y
# um_insert_x ,um_insert_y
# or
# m_find_x ,m_find_y
# um_find_x ,um_find_y
# or
# m_delete_x ,m_delete_y
# um_delete_x ,um_delete_y
# or
plt.plot(m_delete_x ,m_delete_y, label = 'map')
plt.plot(um_delete_x ,um_delete_y, label = 'unordered_map')

plt.xlabel('size')
plt.ylabel('time')

plt.title('delete')

plt.legend()
plt.show()