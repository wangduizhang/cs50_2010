#_*_coding:utf-8
#统计词典信息


def main(filename):
    list_len = [0,0,0,0,0,0,0,0,0,0,0,0,0,0];
    m_ax = 0
    with open(filename,"r") as f:
        lines = f.readlines()
        for i in lines:
            if len(i) > m_ax:
                m_ax = len(i)
            if len(i) == 1:
                list_len[0] += 1
            elif len(i) == 2:
                list_len[1] += 1
            elif len(i) == 3:
                list_len[2] += 1
            elif len(i) == 4:
                list_len[3] += 1
            elif len(i) == 5:
                list_len[4] += 1
            elif len(i) == 6:
                list_len[5] += 1
            elif len(i) == 7:
                list_len[6] += 1
            elif len(i) == 8:
                list_len[7] += 1
            elif len(i) == 9:
                list_len[8] += 1
            elif len(i) == 10:
                list_len[9] += 1
            elif len(i) == 11:
                list_len[10] += 1
            elif len(i) == 12:
                list_len[11] += 1
            elif len(i) == 13:
                list_len[12] += 1
            else:
                list_len[13] += 1

    for i in range(1,14):
        if i == 13:
            print "other:%d" %  list_len[i]
            break

        print "len:%d has number of %d" % (i,list_len[i])
        i += 1

    print "max len :%d" % m_ax

if __name__ == '__main__':
    main('large.txt')