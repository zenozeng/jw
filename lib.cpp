bool fexists(const char *filename) {
    ifstream ifile(filename);
    return ifile;
}
