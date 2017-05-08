import java.util.*;
import java.text.*;

class DateException extends Exception {
    private int year;
    private int month;
    private int day;

    public DateException(String s) {
        super(s);
    }

    public DateException(int y, int m, int d) throws DateException {
        super("building");
        if (y < 1900 || y > 2100)
            throw new DateException("year is illegal");
        if (m < 1 || m > 12)
            throw new DateException("month is illegal");
        if (d < 1 || d > 31)
            throw new DateException("day is illegal");
        if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31)
            throw new DateException("day is illegal");
        if (m == 2)
            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
                if (d > 29)
                    throw new DateException("day is illegal");
            } else {
                if (d > 28)
                    throw new DateException("day is illegal");
            }
        year = y;
        month = m;
        day = d;
    }

    public Date getDate() throws ParseException {
        String s = this.year + "-" + this.month + "-" + this.day;
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-mm-dd");
        return sdf.parse(s);
    }
}

public class DateExceptionTest {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        try {
            int year = scan.nextInt();
            int month = scan.nextInt();
            int day = scan.nextInt();
            DateException de = new DateException(year, month, day);
            Date d = de.getDate();

            SimpleDateFormat sdf = new SimpleDateFormat("yyyy-mm-dd");
            System.out.println(sdf.format(d));
        } catch (InputMismatchException e) {
            System.out.println(e.toString() + " need Integer");
        } catch (DateException e) {
            System.out.println(e.toString());
        } catch (ParseException e) {
            System.out.println(e.toString() + "can't change to date");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}