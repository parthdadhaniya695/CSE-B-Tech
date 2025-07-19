import { ComponentFixture, TestBed } from '@angular/core/testing';

import { MockDemoComponent } from './mock-demo.component';

describe('MockDemoComponent', () => {
  let component: MockDemoComponent;
  let fixture: ComponentFixture<MockDemoComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [MockDemoComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(MockDemoComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
