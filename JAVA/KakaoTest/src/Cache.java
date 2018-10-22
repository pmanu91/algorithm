import java.util.ArrayList;
import java.util.List;

public class Cache {

	static List<String> cache = new ArrayList<>();
	static int processTime = 0;
	
	public static void main(String[] args) {

//		String[] cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
//		String[] cities = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul","Jeju", "Pangyo", "Seoul"};
		String[] cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco","Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
		run(5, cities);
	}
	
	public static void run(int cacheSize, String[] cities) {
		
		for (int i=0; i<cities.length; i++) {
			
			boolean hasCache = false;
			
			for (int j=0; j<cache.size(); j++) {
				if (cache.get(j).equals(cities[i])) {
					// 해당 아이템이 캐시에 존재하면
					hasCache = true;
					cache.remove(j);
					break;
				}
			}
			
			if (hasCache) {
				processTime++;
				putCache(cacheSize, cities[i]);
			} else {
				processTime += 5;
				putCache(cacheSize, cities[i]);
			}
		}
		
		System.out.println(processTime);
	}
	
	public static void putCache(int cacheSize, String city) {
		if (cache.size() < cacheSize) {
			// 캐시 공간이 남으면
			cache.add(city);
		} else {
			// 캐시 공간이 꽉 찼으면
			// 가장 오래된 캐시(리스트의 마지막)를 삭제하고 넣음
			cache.remove(0);
			cache.add(city);
		}
	}
}
