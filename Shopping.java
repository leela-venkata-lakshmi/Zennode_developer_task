import java.util.Scanner;

public class ShoppingCart {

    public static int discountRule1(int cartTotalPrice) {
        int discountAmount = 0;
        if (cartTotalPrice > 200) {
            cartTotalPrice = cartTotalPrice - 10;
            discountAmount = 10;
        }
        return discountAmount;
    }

    public static int discountRule2(int max) {
        int discountAmount = 0;
        if (max > 10) {
            max = max * 20;
            int temp = (int) (max * 0.95);
            discountAmount = max - temp;
        }
        return discountAmount;
    }

    public static int discountRule3(int cartTotal, int cartTotalPrice) {
        int discountAmount = 0;
        if (cartTotal > 20) {
            int temp = (int) (cartTotalPrice * 0.90);
            discountAmount = cartTotalPrice - temp;
        }
        return discountAmount;
    }

    public static int discountRule4(int max, int cartTotal) {
        int discountAmount = 0;
        if (cartTotal > 30) {
            if (max > 15) {
                int temp = max - 15;
                temp *= 50;
                temp /= 2;
                discountAmount = temp;
            }
        }
        return discountAmount;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("The quantity of product A:");
        int A = scanner.nextInt();
        System.out.println("The quantity of product B:");
        int B = scanner.nextInt();
        System.out.println("The quantity of product C:");
        int C = scanner.nextInt();

        int max = Math.max(Math.max(A, B), C);
        String discountName;
        int discountAmount;

        double cartTotal = A + B + C;
        System.out.println("product: A " + A + " " + A * 20);
        System.out.println("product: B " + B + " " + B * 40);
        System.out.println("product: C " + C + " " + C * 50);
        
         int cartTotalPrice = (A * 20) + (B * 40) + (C * 50);
        System.out.println("Sub total:" + cartTotalPrice);

        int flat10Discount = discountRule1(cartTotalPrice);
        int bulk5Discount = discountRule2(max);
        int bulk10Discount = discountRule3((int) cartTotal, cartTotalPrice);
        int tiered50Discount = discountRule4(max, (int) cartTotal);
        
        if(flat10Discount>=bulk5Discount && flat10Discount>=bulk10Discount && flat10Discount>=tiered50Discount)
        {
            discountAmount=flat10Discount;
            discountName="flat_10_discount";
            
        }else if(tiered50Discount>=flat10Discount && tiered50Discount>=bulk5Discount &&  tiered50Discount>=bulk10Discount)
        {
            discountAmount=tiered50Discount;
            discountName="tiered_50_Discount";
            
        }else if(bulk10Discount>=tiered50Discount && bulk10Discount>=bulk5Discount && bulk10Discount>=flat10Discount)
        {
            discountAmount=bulk10Discount;
            discountName="bulk_10_discount ";
            
        }else
        {
            discountAmount=bulk5Discount;
            discountName="bulk_5_discount";
        }

        System.out.println("Discount Name is: " + discountName);
        System.out.println("Discount Amount is: " + discountAmount);

        int totalAmount = cartTotalPrice-discountAmount;

        System.out.println("Enter yes if your product is wrapped as a gift?");
        String giftWrap = scanner.next();

        if ("yes".equals(giftWrap)) {
            System.out.println("Gift wrap fee is: " + cartTotal);
            totalAmount += cartTotal;
        } else {
            System.out.println("Gift wrap fee is: 0");
        }

        cartTotal = Math.ceil(cartTotal / 10);
        totalAmount = totalAmount + (int) (cartTotal * 5);
        System.out.println("Shipping fee is: " + (int) (cartTotal * 5));
        System.out.println("Total amount is: " + totalAmount);
    }
}
