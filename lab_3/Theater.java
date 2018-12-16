public class Theater extends CommonBuilding {

    @Override
    public void capasity(int a){
        System.out.println("Театр имеет вместимость " + a + " человек");
    }

    @Override
    public void floors(int a){
        System.out.println("Театр " + a + " этажный");
    }
}
