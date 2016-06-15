import static java.lang.System.*;

public class ex10 {
	public static void main (String[] args)
	{
	int i = 0;
	
	// go through each string in argv
	// why am I skipping argv[0]?
	for (i = 0; i < args.length; i++){
		System.out.println("arg " + i + ": " + args[i]);
	}
	System.out.println();

	// let's make our own array of strings
	// this array is two dimensional
	// each string is one element
	// each character being another
	String states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};

	int num_states = 4;

	for(i = 0; i < num_states; i++){
		System.out.println("state " + i + ": " + states[i]);
	}

}
}

/* for(INTIALIZER; TEST; INCREMENTER) {
 * 	CODE;
 * }
 *
 * INTIALIZER code that is run to setup loop
 * TEST if false loop doesn't run
 * CODE does what it do
 * INCREMENTER is run
 * TEST...
 */
