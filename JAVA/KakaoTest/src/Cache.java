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
					// �ش� �������� ĳ�ÿ� �����ϸ�
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
			// ĳ�� ������ ������
			cache.add(city);
		} else {
			// ĳ�� ������ �� á����
			// ���� ������ ĳ��(����Ʈ�� ������)�� �����ϰ� ����
			cache.remove(0);
			cache.add(city);
		}
	}
}
