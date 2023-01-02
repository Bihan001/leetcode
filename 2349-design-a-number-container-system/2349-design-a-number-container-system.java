class NumberContainers {

    HashMap<Integer,TreeSet<Integer>> map;
    HashMap<Integer,Integer> mm;

    public NumberContainers() {
        this.map = new HashMap<>();
        this.mm = new HashMap<>();
    }
    
    public void change(int index, int number) {
        if(mm.containsKey(index)) {
            int oldNumber = mm.get(index);
            map.get(oldNumber).remove(index);
            if(map.get(oldNumber).size() == 0) map.remove(oldNumber);
        }
        map.putIfAbsent(number,new TreeSet<>());
        map.get(number).add(index);
        mm.put(index,number);
    }
    
    public int find(int number) {
        if(!map.containsKey(number)) return -1;
        return map.get(number).first();
    }
}


/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */