test=imread('test.jpg');
test(1,:) =0;

for i = 0:1:1000000
	test(randi(478),randi(388)) = 0;
    image(test);
    pause(0.01);
end

image (test);

